# Acelerômetro Software 

## **Descrição**

Este software foi desenvolvido para processar e analisar dados de um acelerômetro. Ele oferece funcionalidades para selecionar um arquivo de log, escolher um local para salvar os resultados dos angulos pitch e roll e iniciar o processamento dos dados.
Como foi realizada esta tarefa:

## **Primeiro passo v0.1.0**

1. Estudo Preliminar

Antes de iniciar o desenvolvimento, foi realizado um estudo sobre os princípios de funcionamento dos acelerômetros e o formato dos dados fornecidos pelo log. Esse estudo foi crucial para entender como interpretar e processar os dados brutos fornecidos pelo dispositivo.
As equações para detecção foram utilizadas as equações 25 e 26 da bibliografia cedida pela Hexagon. 
A equação 25 possui uma indeterminação, mas para debug inicial e facilidade de implementação foi utilizada ela, em versões posteriores seria necessário reavaliar essas contas.

2. Desenvolvimento do Módulo de Processamento

Arquivos Principais:

    Acelerometro.h: Contém a definição da classe Acelerometro e seus métodos para carregar dados, calcular ângulos e salvar resultados.
    Acelerometro.cpp: Implementação dos métodos definidos em Acelerometro.h.

Funcionalidades Desenvolvidas:

    Carregamento de Dados: A classe Acelerometro foi projetada para ler dados de um arquivo e armazená-los em uma estrutura apropriada.
    Cálculo dos Ângulos: Utilizando os dados carregados, o software calcula os ângulos de roll e pitch para cada leitura do acelerômetro.
    Salvar Resultados: Após o cálculo, os resultados são salvos em um arquivo de texto para posterior análise.

3. Código de Teste

Para validar o funcionamento correto dos módulos desenvolvidos, foi criado um programa principal (main.cpp). Este programa instanciou a classe Acelerometro, carregou os dados de um arquivo de log específico e executou o cálculo dos ângulos, salvando os resultados em um arquivo de saída.

4. Pontos de Atenção

    Fator de Escala: O código assume um fator de escala fixo para converter as leituras do acelerômetro em unidades de gravidade (g's). Em aplicações reais, este fator pode variar e deve ser calibrado adequadamente.

   Ausência de Interface: Nesta versão inicial, não foi desenvolvida uma interface gráfica. Todos os parâmetros, como o caminho do arquivo de log e o nome do arquivo de saída, foram hardcoded no programa principal.

   Equações com indeterminação: Necessária troca da equação 25.

5. Conclusão

Este primeiro passo no desenvolvimento do software focou na criação de um módulo robusto para processar e analisar os dados fornecidos por um acelerômetro. Com os módulos macro desenvolvidos e testados, o próximo passo seria integrá-los a uma interface gráfica para facilitar o uso e expandir as funcionalidades do software.

## **Segundo passo v0.2.0**

O foco deste estágio foi na integração de uma interface de usuário (UI) e na revisão das equações de cálculo dos ângulos.
Desenvolvimento da Interface de Usuário
1. Ferramenta de Desenvolvimento

Para a criação da interface de usuário, foi utilizado o Qt Designer, uma ferramenta gráfica fornecida pelo framework Qt, que permite a criação rápida e intuitiva de interfaces.

2. Arquivos de Interface Gerados

Foram gerados três arquivos principais:

    mainwindow.h: Define a classe principal da janela, que contém os slots para os eventos dos botões e outras funcionalidades relacionadas à UI.
    ui_mainwindow.h: Este arquivo é gerado automaticamente pelo Qt Designer e contém a definição da UI, como a disposição dos widgets (botões, labels, etc.).
    mainwindow.cpp: Contém a implementação dos métodos e slots definidos na classe principal e utiliza os elementos da UI definidos em ui_mainwindow.h.

3. Funcionalidades da Interface

A interface desenvolvida possui os seguintes elementos:

    Botão para Seleção de Arquivo: Permite ao usuário escolher um arquivo .log contendo os dados do acelerômetro.
    Botão para Seleção de Local de Saída: Permite ao usuário escolher um local e nome para salvar o arquivo de resultados em .txt.
    Botão "Start": Ao ser pressionado, inicia o processamento dos dados, cálculo dos ângulos e geração do arquivo de resultados.

4. Revisão das Equações de Ângulos

Durante esta etapa, foi identificado e corrigido um erro nas equações de cálculo dos ângulos. As equações para os ângulos de roll e pitch estavam invertidas no código original. Após a revisão, as equações foram corretamente implementadas, garantindo a precisão dos cálculos realizados pelo software.

5. Conclusão

A integração da interface de usuário e a correção das equações de cálculo representam um avanço significativo no desenvolvimento do software. Com a interface, o software torna-se mais acessível e intuitivo para os usuários, permitindo uma interação mais fácil e eficiente com as funcionalidades de análise de dados. A correção das equações garante a precisão e confiabilidade dos resultados gerados, consolidando o software como uma ferramenta robusta para análise de dados de acelerômetro.

## **Terceiro passo v0.3.0**

O foco desta etapa foi otimizar o código, corrigir equações e aprimorar a qualidade geral do software.

Melhorias e Correções Realizadas

1. Refatoração e Limpeza do Código

    Organização e Comentários: O código foi revisado para garantir uma estrutura mais limpa e compreensível. Foram adicionados comentários e documentação para facilitar a manutenção e compreensão do código.

2. Correção das Equações de Cálculo dos Ângulos

    Equação 25: Identificou-se uma indeterminação na Equação 25 original. Esta foi corrigida utilizando a Equação 38, que oferece uma solução mais precisa e confiável.

    Termo de Sinal para GpzGpz​: Foi introduzido um termo de sinal para GpzGpz​ que pode ser 1 ou -1. Este termo foi adicionado para recuperar o sinal perdido de GpzGpz​ ao realizar a operação de raiz quadrada, garantindo resultados mais precisos.

    Fator μμ: Um novo fator, μμ, foi introduzido no cálculo do ângulo de roll ϕϕ. Este fator, inicialmente definido como 0.01, foi utilizado para evitar a indeterminação no denominador da equação, proporcionando uma maior estabilidade e robustez aos cálculos.

3. Resultados em TXT

    Arquivo de Exemplo: O software gerou um arquivo de resultados em formato TXT contendo um exemplo de saída gerada pelo software. Este arquivo serve como um guia para os usuários, demonstrando o formato e conteúdo dos resultados gerados. E claro o resultado do teste o qual é pedido em enunciado.

## **Estrutura final do projeto**

Tecnologias Utilizadas:

    Qt para a interface gráfica.
    C++ para a lógica de processamento.
    Git para o controle de versão.

Estrutura do Projeto:

    mainwindow.h: Contém a definição da classe MainWindow e suas funções e slots.
    mainwindow.cpp: Implementação das funções da classe MainWindow, incluindo os slots para os botões.
    ui_mainwindow.h: Interface gerada automaticamente pelo Qt para a MainWindow.
    Acelerometro.h e Acelerometro.cpp: Classes e métodos relacionados ao processamento dos dados do acelerômetro.

Como compilar e executar o software:
Pré-requisitos:

    Qt Creator instalado versão 5 ou 6.
    Compilador C++.
    Bibliotecas e ferramentas de desenvolvimento Qt.

Passos:

    Clonando o Repositório:
        Clone o repositório usando: git clone <url_do_repositorio>.

    Configurando e Compilando no Qt Creator:
        Abra o Qt Creator.
        Abra o projeto navegando até o diretório clonado.
        Abra o CMakeLists.txt do projeto.
        Compile o projeto usando o Qt Creator.

    Executando o Software:
        Após a compilação, execute o software diretamente do Qt Creator ou navegue até o diretório do executável gerado e execute-o.

        
