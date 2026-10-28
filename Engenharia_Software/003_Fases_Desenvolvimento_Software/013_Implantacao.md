# A Etapa de Implantação de Software

A **Implantação** (ou *Deployment*) é a fase final do ciclo de vida técnico do desenvolvimento. É o momento em que o software deixa o ambiente seguro e controlado da equipe de engenharia e passa a residir no ambiente real do cliente ou nos servidores de produção. 

Como destaca a literatura clássica (como **Sommerville, 2007**), a implantação não é um evento único, mas um processo complexo que envolve o gerenciamento de versões, logística de distribuição, suporte técnico e garantia de que o usuário final consiga extrair valor do sistema.

---

## Atividades Fundamentais da Implantação

O processo de implantação é composto por cinco atividades operacionais e estratégicas interdependentes:

* **Produção de Releases Externos do Software**
  * **O que é:** Consiste em definir o momento exato em que o conjunto de códigos implementados e testados está estável o suficiente para se tornar uma versão oficial de mercado (ex: Versão 1.0.0).
  * **Na prática:** Envolve a criação de marcas de histórico permanentes no repositório de código (*Git Tags*) e a redação do documento de notas de lançamento (*Release Notes*), que detalha para os clientes quais novos recursos foram adicionados e quais bugs foram corrigidos naquela versão.

* **A Embalagem do Software (*Packaging*)**
  * **O que é:** O ato de agrupar o código-fonte compilado, bibliotecas, arquivos de configuração, scripts de banco de dados e recursos visuais em um único pacote de distribuição integrado, protegido e compacto.
  * **Na prática:** Na engenharia moderna, isso se traduz na criação de instaladores executáveis, pacotes zipados padronizados ou, de forma muito comum na arquitetura atual, na geração de **Imagens de Containers (como Docker)**, que garantem que o software empacotado rode da mesma forma em qualquer servidor.

* **Distribuição do Software**
  * **O que é:** A logística técnica necessária para mover o pacote de software gerado na fase de embalagem até os servidores de produção ou até o dispositivo do usuário final.
  * **Na prática:** Depende da categoria do software. Para aplicativos móveis, envolve o envio para as lojas oficiais (Google Play e Apple App Store). Para sistemas Web corporativos na nuvem, envolve a transferência automatizada através de pipelines de **CD (Continuous Deployment)** para servidores como AWS ou Azure.

* **Instalação do Software**
  * **O que é:** A execução prática do pacote de software no ambiente de destino, configurando os caminhos de rede, aplicando as permissões de segurança e executando os scripts necessários para estruturar o banco de dados relacional (as tabelas e chaves).
  * **Na prática:** Envolve validar se a infraestrutura de destino cumpre todos os pré-requisitos técnicos de hardware e sistema operacional necessários para o software rodar sem gargalos.

* **Prestação de Ajuda e Assistência aos Usuários**
  * **O que é:** A estruturação dos mecanismos de suporte técnico, canais de atendimento e documentação de apoio para garantir que a transição para o novo software não cause caos operacional no cliente.
  * **Na prática:** Inclui o fornecimento de Manuais do Usuário (em formato impresso ou wikis virtuais), realização de treinamentos operacionais com as equipes-chave (*Key Users*) e a estruturação de uma central de ajuda (*Help Desk*) para receber, categorizar e corrigir incidentes nos primeiros dias após o lançamento.

---

## Estratégias Modernas de Implantação (Complemento Técnico)

Para enriquecer sua documentação de Engenharia de Software, vale a pena citar as três estratégias de virada de chave de ambiente mais utilizadas pelo mercado para mitigar riscos de indisponibilidade:

* **Implantação In-Place (Tradicional):** O sistema antigo é desligado e a nova versão é instalada por cima no mesmo servidor. Apresenta alto risco de gerar tempo de inatividade (*downtime*) se algo der errado.
* **Implantação Blue-Green:** Mantém-se dois ambientes de servidores idênticos rodando em paralelo. O ambiente "Blue" roda a versão antiga com os usuários reais, enquanto a equipe instala e testa a nova versão no ambiente "Green". Quando tudo está validado, o roteador de tráfego é alterado instantaneamente para o ambiente Green, reduzindo o tempo de queda para zero.
* **Implantação Canary (Canário):** A nova versão do software é liberada inicialmente para apenas uma parcela minúscula e selecionada de usuários (ex: 5% da base). Se nenhum bug crítico for detectado nos logs desses usuários "canários", a atualização é expandida gradualmente para o restante do público.
