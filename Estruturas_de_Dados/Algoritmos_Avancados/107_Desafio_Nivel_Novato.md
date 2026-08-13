# Desafio: Mapa Interativo da Mansão no Detective Quest

Este documento apresenta a especificação técnica e as diretrizes de desenvolvimento para o sistema de navegação e mapeamento de cenários do jogo **Detective Quest**, desenvolvido pela Enigma Studios. O objetivo do projeto é aplicar os conceitos de estruturas de dados hierárquicas não lineares (Árvores Binárias) para criar um mapa de cômodos explorável por meio de escolhas direcionais.

---

## 1. Visão Geral do Desafio

No jogo de investigação Detective Quest, o usuário precisa explorar os cômodos de uma mansão para coletar pistas e localizar o suspeito de um crime. Como desenvolvedor(a) técnico(a), você será responsável por construir a inteligência por trás desse mapa de navegação. 

O mapa da mansão será representado por uma árvore binária montada automaticamente em tempo de execução via alocação dinâmica de memória. O jogador iniciará sua jornada obrigatoriamente no nó raiz (*Hall de Entrada*) e poderá digitar comandos de direção para caminhar pelas ramificações. A exploração continuará de forma ativa até que o usuário atinja um cômodo final sem saídas subsequentes (um nó-folha na árvore), encerrando a investigação daquela ala.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As funcionalidades obrigatórias que determinam o comportamento do motor do mapa são:

1. **Estrutura de Cômodos Hierárquica:** Criação de uma árvore binária para mapear a Mansão Enigma, onde cada nó representa uma sala física.
2. **Atributo da Sala:** Cada cômodo deve carregar o atributo `nome` configurado como uma string de caracteres (ex: *Sala de Estar*, *Cozinha*, *Biblioteca* ou *Jardim*).
3. **Construção Automatizada:** A mansão deve ser montada de forma estática e automática pelo próprio código-fonte dentro do bloco principal `main()`, utilizando chamadas encadeadas da função `criarSala()`. O jogador não cria salas manualmente.
4. **Navegação Interativa e Contínua:** O sistema deve ler os comandos do usuário permitindo que ele escolha ir para a **esquerda (e)** ou para a **direita (d)** em cada sala ativa.
5. **Travessia até o Caso Base:** O loop de exploração deve rodar continuamente até que o jogador alcance um nó-folha (sala que possua ambos os ponteiros de filhos em `NULL`) ou digite o comando de **sair (s)**.
6. **Histórico de Varredura:** O programa deve imprimir na tela o nome de cada cômodo que foi visitado pelo detetive ao longo do percurso de investigação.

### Requisitos Não Funcionais
Critérios de qualidade e organização do código-fonte:

* **Usabilidade Clara:** A interface de texto no terminal deve ser limpa, direta e orientativa, guiando o detetive passo a passo em suas decisões sobre qual porta abrir.
* **Legibilidade e Código Limpo:** O código deve estar bem tabulado e organizado, adotando uma nomenclatura intuitiva de identificadores para variáveis e ponteiros.
* **Documentação Obrigatória:** Inclusão de comentários detalhados explicando a finalidade das três seções principais do arquivo:
  * `criarSala()`: Aloca e cria dinamicamente uma sala com o nome recebido.
  * `explorarSalas()`: Gerencia o laço de navegação e as escolhas direcionais do jogador pela árvore.
  * `main()`: Instancia a raiz, monta o esqueleto da mansão e dispara o início da jogabilidade.

---

## 3. Diretrizes de Simplificação e Escopo

Por se tratar de um módulo estrutural voltado para o nível iniciante, as seguintes restrições de arquitetura devem ser estritamente respeitadas:
* **Árvore Estática:** O foco reside puramente no percorrimento hierárquico. Não devem ser implementadas funções complexas de balanceamento, rotação ou inserção/remoção dinâmica de nós em tempo de execução.
* **Interface Direta:** O menu de opções deve coletar entradas de caracteres simples (`'e'`, `'d'`, `'s'`), rejeitando comandos inválidos de forma amigável sem quebrar a execução.

---

## 4. Estrutura de Arquitetura e Mapa (Arte ASCII)

O arranjo estrutural padrão montado para o fluxo de testes do detetive organiza os ponteiros no Heap seguindo o desenho hierárquico abaixo:

```text
               [ Hall de Entrada ]           <── (Nó Raiz / Início do Jogo)
                 /             \
                /               \
         [ Sala de Estar ]    [ Biblioteca ]  <── (Nós Internos / Opções e/d)
           /           \
          /             \
      [ Quarto ]       [ NULL ]              <── (Nós Folhas / Fim de Linha)
```

---

## 5. Guia de Entrega e Versionamento (Tutorial Git)

A publicação e a submissão do desafio dentro da plataforma do GitHub Classroom devem seguir o roteiro operacional abaixo:

1. **Acesso ao Desafio:** Acesse o link de convite oficial enviado pela Enigma Studios para vincular o projeto à sua conta e instanciar o seu repositório privado de desenvolvimento.
2. **Uso do CodeSpaces:** Ative o ambiente de desenvolvimento em nuvem do GitHub CodeSpaces embutido no repositório para editar e testar o código-fonte diretamente pelo navegador.
3. **Codificação e Arquivos:** Trabalhe exclusivamente em cima dos arquivos modelo preexistentes na árvore de pastas. Não crie novos arquivos ou modifique a nomenclatura das pastas originais.
4. **Comentários de Auditoria:** Comente obrigatoriamente todas as seções do código-fonte. Explique detalhadamente o propósito das variáveis, a verificação de ponteiros nulos (`== NULL`) que barram a navegação e o fluxo de chamadas do menu.
5. **Commit e Push Final:** No terminal do CodeSpaces, execute os comandos do Git para salvar o progresso e realizar o upload definitivo para os servidores de correção automática do GitHub Classroom:
   ```bash
   git add .
   git commit -m "Implementacao do mapa interativo de comodos - Detective Quest"
   git push origin main
   ```
