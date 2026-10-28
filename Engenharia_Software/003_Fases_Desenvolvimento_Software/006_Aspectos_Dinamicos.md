# Detalhamento dos Aspectos Dinâmicos do Sistema

Enquanto os aspectos estáticos definem a estrutura física e a espinha dorsal do software (como as classes, atributos e seus relacionamentos fixos), os **aspectos dinâmicos do sistema** descrevem o comportamento do software ao longo do tempo. 

Esta etapa da Engenharia de Software detalha **como os objetos interagem entre si, como trocam mensagens e como mudam de estado** para executar uma funcionalidade ou responder aos estímulos do usuário e do ambiente.

---

## Conceitos Básicos e Entendimento

O detalhamento dinâmico impede que o sistema seja apenas um conjunto de dados estáticos sem vida. Na programação orientada a objetos (POO), a dinâmica acontece por meio do **envio de mensagens** (chamadas de métodos) entre instâncias de classes.

Para mapear e detalhar essa dinâmica, a Engenharia de Software apoia-se principalmente em dois diagramas comportamentais da UML (Unified Modeling Language):

* **Diagrama de Sequência:** Foca na ordenação temporal das mensagens trocadas entre objetos para realizar um caso de uso específico.
* **Diagrama de Transição de Estados:** Foca no ciclo de vida de um único objeto, mapeando como os valores de seus atributos mudam em resposta a eventos (ex: uma alocação mudando de status de "Ativa" para "Encerrada").

---

## Organograma Dinâmico (Fluxo de Execução)

Para visualizar a colaboração dinâmica e a troca de mensagens em um fluxo de negócio típico (utilizando o contexto de `Empregado` e `Alocação`), mapeamos o comportamento temporal através do organograma linear abaixo:

* **Passo 1: Ator (Usuário/Gestor)**
  * Solicita ao sistema a alocação de um funcionário em um departamento ➔ **Objeto: Sistema (Controlador)**
* **Passo 2: Objeto: Sistema (Controlador)**
  * Consulta a existência do funcionário e do setor ➔ **Objetos: Empregado e Departamento**
  * Se válidos, invoca o construtor do registro ➔ **Objeto Associativo: Alocação**
* **Passo 3: Objeto Associativo: Alocação**
  * Cria a instância, carimba a data atual e define o status inicial como `Pendente` ➔ **Retorna confirmação ao Sistema**
* **Passo 4: Objeto: Sistema (Controlador)**
  * Vincula as tarefas obrigatórias àquela escala de trabalho ➔ **Objeto: Atividade**

---

## Exemplo Prático de Código Dinâmico

Abaixo está a implementação de uma classe controladora de fluxo (`OrquestradorDeAlocacao`) que demonstra a colaboração e a troca de mensagens dinâmicas entre as entidades do sistema.

***
```csharp
using System;
using System.Collections.Generic;

namespace SistemaRH.Dinamico
{
    // Enumeração para representar o Ciclo de Vida/Estado da Alocação
    public enum EstadoAlocacao
    {
        Pendente,
        Ativa,
        Encerrada
    }

    // Classe Orquestradora que demonstra a Interação Dinâmica do Sistema
    public class OrquestradorDeAlocacao
    {
        private readonly List<AlocacaoRefinada> _repositorioAlocacoes = new List<AlocacaoRefinada>();

        // Método que executa a dinâmica de criar e ativar uma alocação
        public void ExecutarFluxoAlocacao(Empregado funcionario, Departamento setor, List<Atividade> tarefas)
        {
            Console.WriteLine(\$"[DINÂMICA] Iniciando fluxo de alocação para: {funcionario.Nome}");

            // 1. Instanciação dinâmica (Troca de mensagens estrutural)
            var novaAlocacao = new AlocacaoRefinada(funcionario, setor, DateTime.Now);

            // 2. Transição de estado baseada em comportamento
            novaAlocacao.AtivarAlocacao();

            // 3. Loop dinâmico de interação com objetos do tipo Atividade
            foreach (var tarefa in tarefas)
            {
                novaAlocacao.VincularAtividade(tarefa);
            }

            _repositorioAlocacoes.Add(novaAlocacao);
            Console.WriteLine(\$"[DINÂMICA] Fluxo concluído com sucesso. Estado Atual: {novaAlocacao.Estado}");
        }
    }

    // Classe Alocacao estendida para suportar comportamento e estados dinâmicos
    public class AlocacaoRefinada
    {
        public Empregado Funcionario { get; private set; }
        public Departamento Setor { get; private set; }
        public DateTime DataInicio { get; private set; }
        public EstadoAlocacao Estado { get; private set; }
        public List<Atividade> ListaTarefas { get; private set; }

        public AlocacaoRefinada(Empregado funcionario, Departamento setor, DateTime dataInicio)
        {
            Funcionario = funcionario;
            Setor = setor;
            DataInicio = dataInicio;
            Estado = EstadoAlocacao.Pendente; // Estado inicial do ciclo de vida
            ListaTarefas = new List<Atividade>();
        }

        // Método dinâmico que altera o comportamento/estado do objeto
        public void AtivarAlocacao()
        {
            if (Estado == EstadoAlocacao.Pendente)
            {
                Estado = EstadoAlocacao.Ativa;
                Console.WriteLine(\$" -> O objeto Alocação mudou de estado para: {Estado}");
            }
        }

        public void VincularAtividade(Atividade tarefa)
        {
            if (Estado != EstadoAlocacao.Ativa)
            {
                throw new InvalidOperationException("Não é possível vincular atividades a uma alocação que não esteja ativa.");
            }

            ListaTarefas.Add(tarefa);
            Console.WriteLine(\$"   -> Mensagem enviada: Tarefa '{tarefa.Nome}' vinculada dinamicamente.");
        }
    }

    // Classes mockadas apenas para compilação estável do exemplo
    public class Empregado { public string Nome { get; set; } }
    public class Departamento { public string Nome { get; set; } }
    public class Atividade { public string Nome { get; set; } }
}
```
***
