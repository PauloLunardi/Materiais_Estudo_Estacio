# Mapeamento Objeto-Relacional (ORM)

No desenvolvimento de sistemas orientados a objetos que utilizam bancos de dados relacionais para persistência, a equipe de engenharia enfrenta um desafio técnico clássico conhecido como **Descompasso de Impedância** (*Impedance Mismatch*). O **Mapeamento Objeto-Relacional (ORM - Object-Relational Mapping)** é a solução tecnológica e conceitual utilizada para superar esse problema, integrando esses dois paradigmas.

---

## O Conceito e o Problema do Descompasso

O conflito surge porque as duas tecnologias enxergam e estruturam os dados de maneiras completamente diferentes:

* **O Mundo Orientado a Objetos (Software):** Baseia-se em conceitos como classes, instâncias (objetos), encapsulamento, herança, polimorfismo e associações complexas orientadas por referências de memória.
* **O Mundo Relacional (Banco de Dados):** Baseia-se em tabelas (relações), colunas (atributos), linhas (tuplas), chaves primárias e chaves estrangeiras, operando fundamentado na álgebra relacional.

O **ORM** funciona como uma ponte automatizada. Ele permite que o desenvolvedor interaja com o banco de dados utilizando apenas o código e a lógica de objetos da sua linguagem de programação, enquanto a ferramenta ORM traduz essas operações automaticamente em comandos SQL em tempo real.

---

## Casos Típicos de Mapeamento

Ao integrar os dois padrões, existem três cenários fundamentais de mapeamento de relacionamentos que precisam ser traduzidos do software para o banco:

* **Um-para-Um (1:1):** Um objeto possui referência a apenas um outro objeto (ex: um `Usuario` possui apenas um `Perfil`). No banco, isso se resolve com uma chave estrangeira única em uma das tabelas.
* **Um-para-Muitos (1:N):** Um objeto aponta para uma lista de outros objetos (ex: um `Departamento` possui muitos `Empregados`). No banco, a tabela do lado "Muitos" ganha uma chave estrangeira apontando para o lado "Um".
* **Muitos-para-Muitos (N:N):** Múltiplos objetos de um tipo conectam-se a múltiplos objetos de outro tipo (ex: o cenário clássico de **Bezerra (2014)**, onde um `Empregado` pode participar de várias `Atividades` e uma `Atividade` possui vários `Empregados`).

---

## O que fazer para integrar os dois padrões?

Para realizar a integração de forma limpa e seguindo as boas práticas da arquitetura de software (especialmente isolando o domínio dos serviços técnicos):

1. **Adotar um Framework ORM:** Utilizar ferramentas consolidadas no mercado, como **Entity Framework Core** (para C#/.NET), **Hibernate/JPA** (para Java) ou **Sequelize** (para Node.js).
2. **Definir Metadados de Mapeamento:** Configurar o mapeamento explicitando quais classes correspondem a quais tabelas e quais atributos correspondem a quais colunas. Isso pode ser feito via **Anotações/Attributes** diretamente no código ou via arquivos de configuração separados (**Fluent API**), que é a prática recomendada para manter o domínio limpo.
3. **Gerenciar o Ciclo de Vida com Migrations:** Utilizar ferramentas de migração do ORM para rastrear as mudanças de código nas classes e gerar automaticamente os scripts de atualização estrutural do banco de dados (DDL).

---

## Exemplo Prático de Mapeamento Muitos-para-Muitos (N:N)

Tomando como base o ecossistema .NET com o **Entity Framework Core**, o código abaixo demonstra como mapear uma relação Muitos-para-Muitos pura de forma elegante. 

Nas versões modernas do EF Core, a tabela associativa intermediária do banco de dados é gerada e gerenciada de forma transparente através das propriedades de navegação de coleção em ambas as pontas.

***
```csharp
using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Builders;

namespace SistemaRH.Mapeamento
{
    // ==========================================
    // CLASSES DE DOMÍNIO (ORIENTADAS A OBJETOS)
    // ==========================================

    public class Empregado
    {
        public int Id { get; set; }
        public string Cpf { get; set; }
        public string Nome { get; set; }

        // Propriedade de Navegação: Um Empregado tem muitas Atividades
        public ICollection<Atividade> Atividades { get; set; } = new List<Atividade>();
    }

    public class Atividade
    {
        public int Id { get; set; }
        public string Nome { get; set; }
        public string Descricao { get; set; }

        // Propriedade de Navegação: Uma Atividade pertence a muitos Empregados
        public ICollection<Empregado> Empregados { get; set; } = new List<Empregado>();
    }

    // ==========================================
    // CAMADA DE SERVIÇOS TÉCNICOS (CONFIGURAÇÃO ORM)
    // ==========================================

    // Mapeamento explícito usando Fluent API para isolar o banco de dados das classes de negócio
    public class EmpregadoConfiguration : IEntityTypeConfiguration<Empregado>
    {
        public void Configure(EntityTypeBuilder<Empregado> builder)
        {
            builder.ToTable("TB_EMPREGADO");
            builder.HasKey(e => e.Id);
            builder.Property(e => e.Nome).HasMaxLength(150).IsRequired();
            builder.Property(e => e.Cpf).HasMaxLength(11).IsRequired();

            // CONFIGURAÇÃO DO MUITOS-PARA-MUITOS (N:N)
            builder.HasMany(e => e.Atividades)
                   .WithMany(a => a.Empregados)
                   .UsingEntity(j => j.ToTable("TL_EMPREGADO_ATIVIDADE")); 
                   // O ORM cria automaticamente a tabela de ligação "TL_EMPREGADO_ATIVIDADE" 
                   // contendo as Chaves Estrangeiras (FKs) de ambas as tabelas de origem.
        }
    }

    // Contexto de Conexão do Banco de Dados (DbContext)
    public class AppDbContext : DbContext
    {
        public DbSet<Empregado> Empregados { get; set; }
        public DbSet<Atividade> Atividades { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            // Aplica as configurações do Fluent API mapeadas acima
            modelBuilder.ApplyConfiguration(new EmpregadoConfiguration());
            base.OnModelCreating(modelBuilder);
        }
    }
}
```
***

## O Modelo Relacional na Prática (Visão de Tabelas)

Muitas vezes, ao projetar o banco de dados relacional, a relação Muitos-para-Muitos (N:N) conceitual precisa ser desfeita e mapeada explicitamente por meio de uma **tabela associativa intermediária** (tabela de ligação). Essa tabela conterá chaves estrangeiras apontando para as tabelas principais.

Seguindo a estrutura lógica padronizada para o banco de dados, o mapeamento do relacionamento Muitos-para-Muitos entre `Empregado` e `Projeto` se divide em três tabelas físicas:

```sql
1. Empregado (id, matrícula, CPF, nome, endereço, CEP, idDepartamento)
2. Alocação   (id, idProjeto, idEmpregado)
3. Projeto   (id, nome, verba)
```

### Análise Estrutural do Esquema:

* **Tabelas Fortes (`Empregado` e `Projeto`):** Possuem suas próprias identidades (`id`). Note que a tabela `Empregado` também possui uma chave estrangeira (`idDepartamento`), indicando uma relação de 1:N com a tabela de Departamentos.
* **Tabela Associativa (`Alocação`):** É a tabela que quebra o Muitos-para-Muitos. Ela não existia como uma entidade forte no início, mas surge no banco de dados para ligar um `idEmpregado` a um `idProjeto`. 
  * Se o Empregado Carlos (id 1) for alocado no Projeto Alpha (id 5), nascerá um registro na tabela Alocação: `(id_gerado, 5, 1)`.
