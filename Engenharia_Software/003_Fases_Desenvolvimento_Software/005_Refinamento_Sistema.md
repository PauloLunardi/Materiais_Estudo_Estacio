# Refinamento dos Aspectos Estáticos e Estruturais do Sistema

Após a fase inicial de levantamento de requisitos e modelagem conceitual, a equipe de desenvolvimento realiza o **refinamento dos aspectos estáticos e estruturais do sistema**. Essa etapa transforma diagramas lógicos abstratos (como o mapeamento inicial de regras de negócio) em uma estrutura técnica de classes robusta, pronta para ser codificada de forma limpa, sustentável e reutilizável.

---

## Conceitos Básicos e Entendimento

Os aspectos **estáticos e estruturais** definem a espinha dorsal do software: quais componentes existem, quais atributos eles possuem e como eles se conectam formalmente entre si. Eles não descrevem o comportamento no tempo (dinâmica), mas sim a organização física do código.

O refinamento consiste em aplicar boas práticas de design de software para resolver problemas complexos de acoplamento. Tomando como base o diagrama enviado anteriormente (onde temos `EMPREGADO`, `DEPARTAMENTO` e `ATIVIDADE`), o refinamento introduz **classes associativas** e conceitos de encapsulamento para garantir que:
* Dados não fiquem duplicados ou perdidos no sistema.
* As associações representem a realidade técnica da arquitetura (ex: registrar a data exata em que uma alocação ocorreu).

---

## Organograma Estrutural das Classes

Estrutura estática:

* **Classe: Empregado**
  * Atributos: `- cpf`, `- nome`, `- endereco`
  * Relacionamento: Conecta-se a múltiplos Departamentos através da classe associativa *Alocação*.
* **Classe: Departamento**
  * Atributos: `- nome`
  * Relacionamento: Aloca múltiplos Empregados através da classe associativa *Alocação*.
* **Classe Associativa: Alocação** (Ponte de ligação estrutural)
  * Atributos próprios: `- dataInicio`, `- dataFim`
  * Relacionamento: Detalha o vínculo exato entre Empregado e Departamento, além de se conectar a múltiplas *Atividades*.
* **Classe: Atividade**
  * Atributos: `- nome`, `- descricao`
  * Relacionamento: É exercida dentro de uma Alocação específica.

---

## Exemplo Prático de Código Refinado

***
```csharp
using System;
using System.Collections.Generic;

namespace SistemaRH.Estrutural
{
    // Classe Base: Empregado com encapsulamento adequado
    public class Empregado
    {
        public string Cpf { get; private set; }
        public string Nome { get; private set; }
        public string Endereco { get; private set; }

        public Empregado(string cpf, string nome, string endereco)
        {
            Cpf = cpf;
            Nome = nome;
            Endereco = endereco;
        }
    }

    // Classe Base: Departamento
    public class Departamento
    {
        public string Nome { get; private set; }

        public Departamento(string nome)
        {
            Nome = nome;
        }
    }

    // Classe: Atividade que representa as tarefas a serem executadas
    public class Atividade
    {
        public string Nome { get; private set; }

        public Atividade(string nome)
        {
            Nome = nome;
        }
    }

    // CLASSE ASSOCIATIVA REFINADA: Alocacao
    // Resolve o acoplamento estrutural e guarda o estado da relação (Data)
    public class Alocacao
    {
        public Empregado Funcionario { get; private set; }
        public Departamento Setor { get; private set; }
        public DateTime DataAlocacao { get; private set; }
        public List<Atividade> AtividadesExercidas { get; private set; }

        public Alocacao(Empregado funcionario, Departamento setor, DateTime dataAlocacao)
        {
            Funcionario = funcionario ?? throw new ArgumentNullException(nameof(funcionario));
            Setor = setor ?? throw new ArgumentNullException(nameof(setor));
            DataAlocacao = dataAlocacao;
            AtividadesExercidas = new List<Atividade>();
        }

        public void AdicionarAtividade(Atividade atividade)
        {
            if (atividade != null)
            {
                AtividadesExercidas.Add(atividade);
            }
        }
    }
}
```
***
