# Levantamento de Requisitos e Projeto Conceitual

## 1. Fases do Projeto de Banco de Dados e Coleta de Requisitos

O desenvolvimento de um banco de dados corporativo é uma atividade estruturada, dividida em quatro fases sequenciais bem definidas: levantamento de requisitos, projeto conceitual, projeto lógico e projeto físico. O sucesso do sistema depende diretamente do entendimento das rotinas e tarefas dos colaboradores do negócio. 

* **Foco do Levantamento de Requisitos:** O profissional de dados realiza entrevistas diretas com os usuários e colaboradores para compreender a dinâmica operacional do negócio, capturando e documentando as necessidades de gestão de dados de maneira detalhada e completa.
* **O Conceito de Universo de Discurso:** O banco de dados automatiza uma fração do mundo real, denominada tecnicamente como **minimundo** ou **universo de discurso** (ELMASRI; NAVATHE, 2019).
* **Estudo de Caso Prático (Escola de Treinamento em TI):** A partir de entrevistas simuladas em uma instituição de ensino, foram consolidados os seguintes requisitos de dados primários: 

  * *Cursos:* A escola planeja múltiplos cursos. Cada curso possui nome, descrição, carga horária e deve ser identificado obrigatoriamente por um código único.
  * *Clientes:* O sistema armazena o nome, a data de nascimento, o CPF, o e-mail e um telefone de contato de cada cliente. Cada indivíduo é identificado por um código único.
  * *Inscrições:* Quando um cliente realiza a inscrição em um curso, o sistema precisa registrar a data em que o evento ocorreu. Caso a inscrição seja cancelada posteriormente, é obrigatório armazenar a data do cancelamento. Um cliente pode se inscrever em diversos cursos.

## 2. O Esquema Conceitual e o Diagrama de Entidade e Relacionamento (DER)

Com os requisitos documentados, a fase de projeto conceitual utiliza modelos gráficos de alto nível para formalizar o entendimento do negócio, sem se preocupar com detalhes técnicos de como os dados serão armazenados fisicamente. 

* **Função do Esquema Conceitual:** Atua como uma referência de alto nível para garantir que todas as necessidades dos usuários sejam atendidas e que as regras de negócio não entrem em conflito (ELMASRI; NAVATHE, 2019). O modelo visual facilita o aprendizado e a validação do sistema junto ao cliente.
* **Elementos Essenciais do DER:** O Diagrama de Entidade e Relacionamento possui três componentes gráficos fundamentais: 

  * *Entidades:* Representadas graficamente por um **retângulo** contendo o seu nome. Identificam os objetos ou conceitos do minimundo (ex: CLIENTE e CURSO).
  * *Relacionamentos:* Representados graficamente por um **losango**, conectado por linhas aos retângulos das entidades participantes. Indicam a associação lógica entre os objetos (ex: um cliente faz inscrição em um ou mais cursos).
  * *Atributos:* Representados graficamente como elementos ligados diretamente à entidade ou ao relacionamento do qual fazem parte, detalhando suas características. No caso da inscrição, atributos como "data de inscrição" e "data de cancelamento" pertencem ao próprio relacionamento.

## 3. Notação Alternativa: Diagrama de Classes UML

Na atuação profissional, não existe uma única convenção visual obrigatória para expressar o modelo de entidade e relacionamento. A escolha da notação depende das políticas da empresa de desenvolvimento ou das ferramentas CASE utilizadas (como a brModelo, que adota a notação clássica original). 

* **Adoção da UML:** A *Unified Modeling Language* (UML) é amplamente utilizada na engenharia de software para documentar componentes. O seu **Diagrama de Classes** funciona na prática como uma notação alternativa e moderna para representar os conceitos de um DER.
* **Estrutura das Classes na UML:** Cada classe é exibida como uma caixa retangular subdividida verticalmente em três seções específicas: 

  1. *Seção Superior:* Exibe estritamente o nome da classe (equivalente ao nome da entidade).
  2. *Seção Central:* Exibe a lista de atributos da classe. Permite opcionalmente tipar os dados inserindo o caractere de dois pontos ":" seguido pelo tipo (ex: cpf : String).
  3. *Seção Inferior:* Inclui as operações e métodos associados aos objetos daquela classe, que serão detalhados mais adiante, durante o projeto das aplicações.
* **Terminologia de Conexão na UML:** 

  * O relacionamento entre as entidades é denominado **associação** e é representado graficamente por uma linha sólida conectando as caixas das classes.
  * Quando um relacionamento possui atributos próprios (como as datas de uma inscrição), esses atributos são inseridos em uma caixa de classe isolada, conectada à linha de associação principal por meio de uma **linha tracejada**.

**Nota de Transição:** Após concluir a validação do DER ou do Diagrama de Classes UML, o projeto avança para a fase de **projeto lógico**, onde a estrutura abstrata é convertida em um modelo de dados de mais baixo nível, diretamente dependente do tipo de SGBD escolhido para a implementação.
