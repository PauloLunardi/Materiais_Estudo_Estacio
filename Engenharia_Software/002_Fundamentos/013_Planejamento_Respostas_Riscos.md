# Planejamento de Respostas aos Riscos

Após identificar, qualificar e quantificar os riscos, a equipe de engenharia e a gerência de projetos não podem adotar uma postura passiva. O **Planejamento de Respostas aos Riscos** é a etapa em que se desenvolvem opções, selecionam-se estratégias e acordam-se ações para lidar com a exposição geral aos riscos do projeto.

O grande objetivo aqui é **minimizar as ameaças** e **maximizar as oportunidades** antes que elas se materializem no ciclo de desenvolvimento do software.

---

## Estratégias para Riscos Negativos (Ameças)

Para lidar com os riscos que podem prejudicar o projeto (como atrasos, estouros de orçamento ou bugs críticos), o Guia PMBOK estabelece quatro estratégias principais:

* **Evitar (Eliminar):** Consiste em agir diretamente no planejamento ou na arquitetura para eliminar completamente a ameaça ou isolar o projeto do seu impacto.
  * *Exemplo no Software:* O time identifica que usar um banco de dados NoSQL complexo e inédito traz o risco de falha arquitetural. A equipe decide *evitar* o risco alterando o projeto técnico para usar um banco de dados Relacional tradicional que todos já dominam.
* **Mitigar (Reduzir):** Consiste em tomar ações preventivas imediatas para reduzir a probabilidade de o risco ocorrer ou diminuir a severidade do seu impacto caso ele aconteça.
  * *Exemplo no Software:* O risco de encontrar bugs críticos antes do lançamento é alto. A equipe *mitiga* o risco implementando uma esteira de testes automatizados unitários e de integração (CI/CD) ao final de cada dia de trabalho.
* **Transferir (Compartilhar o Impacto):** Consiste em passar a responsabilidade e o impacto financeiro/técnico da ameaça para um terceiro. Não elimina o risco, apenas muda o dono.
  * *Exemplo no Software:* Em vez de criar um módulo de processamento de pagamentos interno (com riscos gigantescos de segurança e conformidade PCI), a empresa *transfere* a operação integrando o sistema com um gateway de pagamento consolidado (como Stripe ou PayPal).
* **Aceitar:** É adotada quando não é possível ou viável financeiramente agir preventivamente contra o risco. A equipe reconhece a ameaça e decide lidar com as consequências caso ela ocorra.
  * *Aceitação Passiva:* O time não faz nada, apenas registra o risco e age se ele acontecer.
  * *Aceitação Ativa:* O time cria uma **reserva de contingência** (tempo ou dinheiro) especificamente para cobrir os impactos caso o risco se materialize.

---

## Estratégias para Riscos Positivos (Oportunidades)

Quando a incerteza pode trazer um benefício para o software (como uma entrega mais rápida ou economia de recursos), as estratégias mudam para garantir que a oportunidade seja aproveitada:

* **Explorar:** Eliminar a incerteza associada a uma oportunidade para garantir de forma absoluta que o benefício aconteça.
  * *Exemplo no Software:* Se designar o melhor arquiteto da empresa para o projeto garante que o sistema use um gerador de código que reduz o prazo em 30%, a gerência *explora* a oportunidade alterando a escala do profissional de forma definitiva para esse projeto.
* **Melhorar (Melhoria):** Aumentar a probabilidade de ocorrência ou os impactos positivos de uma oportunidade por meio de ações focadas.
  * *Exemplo no Software:* Fornecer um treinamento rápido sobre um novo framework para a equipe técnica a fim de *melhorar* a chance de eles conseguirem reaproveitar componentes e acelerar a codificação.
* **Compartilhar:** Alocar a propriedade da oportunidade a um terceiro que seja mais capaz de capturar os benefícios para o projeto.
  * *Exemplo no Software:* Fazer uma parceria de desenvolvimento (*Joint Venture*) com uma empresa especialista em Inteligência Artificial para integrar um motor de buscas inteligente ao software de forma muito mais rápida.
* **Aceitar:** Estar disposto a aproveitar o benefício se ele acontecer espontaneamente, mas sem gastar tempo ou recursos tentando forçar a sua ocorrência.

---

## O Registro de Riscos e os Planos de Contingência

Todas essas definições são consolidadas em uma ferramenta viva da documentação chamada **Registro de Riscos**. Para cada resposta planejada, dois elementos técnicos são fundamentais:

* **Gatilho do Risco (*Trigger*):** Um sinal ou indicador claro de que o risco acabou de se materializar e que a resposta precisa ser acionada imediatamente. *Exemplo:* Se a latência do servidor de testes passar de 500ms por 3 dias seguidos, o gatilho é disparado.
* **Plano de Contingência (Plano B):** A lista de passos operacionais exatos que a equipe técnica executará após o gatilho ser acionado. Garante que ninguém entre em pânico e que as ações corretivas sejam cirúrgicas.
