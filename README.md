# Trabalho B1 - Lógica de Programação e Algoritmos

## Descrição

Este projeto é um simulador de entregas para uma empresa fictícia. O programa
processa solicitações de entrega durante uma sessão de atendimento, validando
os dados informados (distância, peso, modalidade, proteção e tentativas
adicionais), calculando o valor de cada entrega conforme as regras de negócio
definidas, e apresentando um resumo estatístico ao final da sessão.

## Funcionalidades

- Leitura e validação da distância da entrega (deve ser maior que zero)
- Leitura e validação do peso da entrega (deve ser maior que zero)
- Leitura e validação da modalidade (1-Econômica, 2-Expressa, 3-Prioritária)
- Leitura e validação da contratação de serviço de proteção (0 ou 1)
- Leitura e validação da quantidade de tentativas adicionais (inteiro >= 0)
- Cálculo do valor-base conforme a faixa de distância
- Cálculo do subtotal inicial (valor-base + distância x tarifa por km)
- Cálculo do adicional de peso sobre o subtotal inicial
- Cálculo do adicional de modalidade sobre o subtotal inicial
- Cálculo do valor final da entrega, incluindo proteção e tentativas adicionais
- Processamento de múltiplas entregas em uma mesma sessão
- Validação da opção de continuar processando (0 ou 1)
- Resumo final da sessão com total de entregas, valor total, valor médio,
  quantidade por modalidade, maior e menor valor de entrega

## Organização da solução

O programa foi dividido em funções com responsabilidades bem definidas,
evitando concentrar a lógica na função `main`:

- **Funções de leitura e validação** (`lerDistancia`, `lerPeso`,
  `lerModalidade`, `lerProtecao`, `lerTentativas`, `lerContinuar`): cada uma
  solicita um dado ao usuário e repete a solicitação enquanto o valor
  informado não for válido, retornando o valor já validado.
- **Funções de cálculo** (`calcularValorBase`, `calcularSubtotalInicial`,
  `calcularAdicionalPeso`, `calcularAdicionalModalidade`,
  `calcularValorFinal`): recebem os dados necessários por parâmetro e
  retornam o valor calculado, seguindo a ordem de cálculo definida nas
  regras de negócio.
- **Função de apresentação** (`exibirResumo`): recebe os contadores e
  acumuladores da sessão e imprime o resumo final, sem retornar valor.
- **Função `main`**: coordena o fluxo geral, chamando as demais funções em
  sequência, controlando o laço de repetição da sessão e atualizando os
  contadores e acumuladores (total de entregas, valor total, quantidade por
  modalidade, maior e menor valor).

## Compilação

No terminal, a partir da raiz do repositório, execute: gcc src/main.c -o programa 

## Execução

Após compilar, execute:

./programa


O programa solicitará os dados de cada entrega e, ao final da sessão
(quando o usuário responder 0 à pergunta sobre continuar), apresentará o
resumo estatístico.

## Uso de Inteligência Artificial

Utilizei a ferramenta Claude (Anthropic) como apoio ao aprendizado durante 
o desenvolvimento deste trabalho.

**Finalidade:** entender o roteiro do trabalho, tirar dúvidas sobre conceitos
de lógica de programação (validação por repetição, contadores, acumuladores,
modularização), configurar o ambiente de desenvolvimento (instalação do
GCC via MSYS2, configuração do VS Code) e o fluxo de versionamento com Git
e GitHub (commits, push, .gitignore) e identificar erros, ensinando como resolver.

**Como foi usado:** o desenvolvimento foi conduzido função por função. Para
cada função em que eu tinha duvidas de como fazer, recebi uma explicação da lógica necessária 
(por exemplo, como validar uma entrada com laço `while`, como aplicar percentuais
sobre o subtotal inicial, como atualizar variáveis de mínimo e máximo).
Eu digitei o código no editor, compilei, testei com valores válidos e inválidos,
e conferi os resultados contra a tabela de casos de teste do roteiro (item 9) antes 
de avançar para apróxima função. Os commits foram feitos de forma progressiva, acompanhando
cada etapa concluída e testada.

**Exemplos de prompts utilizados:**
- "leia o roteiro desse trabalho e me explique o que eu tenho que fazer, mas sem gerar o codigo" 
- "me explica sobre as tentativas adicionais, oque elas fazem mesmo?"
- "vou te mandar o roteiro dnv, e o meu código por inteiro e você vai ler o
  roteiro novamente e analisar se está tudo de acordo com o que a
  professora pediu"
- ïdentifique o erro e me explique porque o codigo nao compila"  

**O que foi aproveitado:** a estrutura de cada função (validação por `while`,
cálculo por faixas com `if/else if`, uso de constantes, parâmetros e retorno)
foi aproveitada e adaptada ao longo da construção do programa.

**Alterações e verificações realizadas:** cada função foi testada
manualmente por mim antes do commit, com valores válidos, valores inválidos
e valores de fronteira. Ao final, revisei o código completo comparando-o
com o roteiro item a item (regras de cálculo, requisitos de modularização,
validações) para confirmar que nada estava incorreto ou faltando.


