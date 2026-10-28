# Detalhamento na Arquitetura de Sistemas

Após refinar os aspectos estruturais (estáticos) e o comportamento dos objetos (dinâmicos), a Engenharia de Software exige uma visão macro para organizar como todas as partes do software vão coexistir, se comunicar e escalar. Esse pilar é o **Detalhamento da Arquitetura de Sistemas**.

Diferente do design de código, que se preocupa com classes e métodos individuais, a arquitetura foca nos **componentes de alto nível**, nos padrões de comunicação, na infraestrutura e nos atributos de qualidade do sistema (como segurança, desempenho, disponibilidade e escalabilidade).

---

## Conceitos Explicativos Fundamentais

Como aponta a literatura clássica de **Pressman (2016)** e **Sommerville (2007)**, a arquitetura de um sistema de software pode ser comparada à planta arquitetônica de um edifício: ela estabelece as diretrizes estruturais que guiarão toda a construção. 

Para detalhar uma arquitetura de forma profissional, os engenheiros apoiam-se em três pilares:

### 1. Padrões Arquiteturais (*Architectural Patterns*)
São soluções prontas e consolidadas para problemas recorrentes de organização de software em larga escala. Eles ditam como o código e os servidores serão organizados (ex: divisão em camadas, separação por microsserviços ou sistemas baseados em eventos).

### 2. Acoplamento e Coesão de Componentes
* **Baixo Acoplamento:** Garante que um módulo ou serviço dependa o mínimo possível do outro. Se o sistema de relatórios falhar, o carrinho de compras do e-commerce deve continuar funcionando.
* **Alta Coesão:** Garante que cada componente técnico possua uma única responsabilidade muito bem focada e delimitada.

### 3. Mecanismos de Integração e Comunicação
Define os protocolos que os componentes usarão para trocar dados. Podem ser comunicações síncronas (onde um componente espera a resposta imediata do outro, como APIs HTTP/REST) ou assíncronas (onde mensagens são disparadas para uma fila sem travar a execução técnica, como sistemas de mensageria).

---

## Representação Estrutural: Arquitetura em Camadas (3-Tier/Multicamadas)

Abaixo está o organograma arquitetural clássico de um sistema de informação empresarial. Ele ilustra o isolamento de responsabilidades técnico do modelo de **Arquitetura em Camadas (N-Tier)**:

* **1. Camada de Apresentação (Front-End)**
  * Interfaces visuais expostas ao usuário final.
  * Tecnologias comuns: Aplicativos móveis (iOS/Android), páginas Web (React, Vue, HTML/CSS).
  * Comunicação: Envia requisições via rede HTTP/JSON para a camada de aplicação.

* **2. Camada de Aplicação e Negócio (Back-End / API)**
  * O "cérebro" do software. Onde rodam as regras de negócio complexas, orquestrações dinâmicas e validações de segurança.
  * Tecnologias comuns: Serviços em C# (.NET), Java (Spring Boot), Node.js ou Python.
  * Comunicação: Recebe dados do Front-End, processa as regras de negócio e aciona o banco de dados.

* **3. Camada de Persistência e Dados (Banco de Dados)**
  * O alicerce onde as informações corporativas são gravadas e mantidas de forma segura e consistente.
  * Tecnologias comuns: SGBDs Relacionais (PostgreSQL, SQL Server, Oracle) ou NoSQL (MongoDB).

---

## Exemplo Prático de Acoplamento Arquitetural

Abaixo está um exemplo de código técnico que demonstra como a **Camada de Aplicação (Back-End)** orquestra a comunicação arquitetural entre as demandas do cliente e a **Camada de Persistência (Banco de Dados)** de forma desacoplada por meio de contratos (Interfaces).

***
```csharp
using System;

namespace SistemaRH.Arquitetura
{
    // CONTRATO ARQUITETURAL: Garante desacoplamento entre as camadas de Aplicação e Dados
    public interface IRepositorioFuncionario
    {
        void SalvarNoBanco(string cpf, string nome);
    }

    // ==========================================
    // CAMADA DE DADOS / PERSISTÊNCIA (Infraestrutura)
    // ==========================================
    public class SqlServerRepositorio : IRepositorioFuncionario
    {
        public void SalvarNoBanco(string cpf, string nome)
        {
            // Simulação técnica de persistência física de dados
            Console.WriteLine(\$"[CAMADA DADOS] Executando comando SQL INSERT para o funcionário: {nome} (CPF: {cpf})");
        }
    }

    // ==========================================
    // CAMADA DE APLICAÇÃO / NEGÓCIO (Core da API)
    // ==========================================
    public class ServicoFuncionario
    {
        private readonly IRepositorioFuncionario _repositorio;

        // Injeção de Dependência: A aplicação não sabe qual banco está usando, apenas conhece a Interface
        public ServicoFuncionario(IRepositorioFuncionario repositorio)
        {
            _repositorio = repositorio ?? throw new ArgumentNullException(nameof(repositorio));
        }

        // Método que executa a lógica da regra de negócio arquitetural
        public void CadastrarNovoFuncionario(string cpf, string nome)
        {
            Console.WriteLine("[CAMADA NEGÓCIO] Validando regras corporativas de admissão...");

            if (string.IsNullOrWhiteSpace(cpf) || string.IsNullOrWhiteSpace(nome))
            {
                throw new ArgumentException("Dados inválidos para admissão.");
            }

            // Envia os dados processados para a próxima camada
            _repositorio.SalvarNoBanco(cpf, nome);
            
            Console.WriteLine("[CAMADA NEGÓCIO] Fluxo de contratação finalizado na arquitetura.");
        }
    }
}
```
***

## Modelo de Arquitetura em Camadas (BEZERRA, 2014)

Conforme a abordagem de análise e projeto de sistemas orientados a objetos descrita por **Bezerra (2014)**, a organização lógica do software é estruturada em **quatro camadas fundamentais**, organizadas de cima para baixo com um fluxo de dependência unidirecional (as camadas superiores conhecem e requisitam as inferiores, mas as inferiores não conhecem as superiores):

* **1. Camada de Apresentação**
  * **O que é:** A interface com o usuário final ou com outros sistemas externos.
  * **Papel:** É responsável por capturar as ações do usuário (cliques, preenchimento de formulários), enviar os dados para processamento e exibir os resultados visuais na tela. Não executa regras de negócio.

* **2. Camada de Aplicação**
  * **O que é:** O ponto de entrada dos fluxos de execução do sistema (controladores ou serviços de aplicação).
  * **Papel:** Orquestra a execução das tarefas, funcionando como uma ponte de comunicação. Ela recebe a requisição da Apresentação, busca os objetos necessários na camada de Domínio e gerencia transações técnicas de alto nível (ex: abrir e fechar conexões).

* **3. Camada de Domínio**
  * **O que é:** O "coração" ou núcleo inteligente do software (onde reside o Modelo de Objetos do sistema).
  * **Papel:** É o componente mais importante. Contém as entidades centrais do negócio (como `Empregado`, `Departamento`, `Alocação`), suas regras operacionais básicas, restrições e validações lógicas independentes de tecnologia.

* **4. Camada de Serviços Técnicos (ou Infraestrutura)**
  * **O que é:** A base técnica de suporte que provê utilitários e serviços de baixo nível para todas as outras camadas.
  * **Papel:** Lida com a infraestrutura física e computacional direta, como comunicação com o Sistema Gerenciador de Banco de Dados (SGBD) para persistência de dados, envio de e-mails, logs de auditoria e criptografia.

---

### Regra de Dependência e Acoplamento no Modelo

Como ilustrado na **Figura 8 (Bezerra, 2014)**, as setas tracejadas indicam a direção permitida para o acoplamento:
1. **Apresentação** depende de **Aplicação** e de **Serviços Técnicos**.
2. **Aplicação** depende de **Domínio** e de **Serviços Técnicos**.
3. **Domínio** depende estritamente de **Serviços Técnicos**, permanecendo isolado de interferências visuais ou de controle de fluxo de tela.
