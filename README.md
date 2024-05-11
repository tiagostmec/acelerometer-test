# Acelerômetro Software Template

## **Descrição**

Este software foi desenvolvido para processar e analisar dados de um acelerômetro. Ele oferece funcionalidades para selecionar um arquivo de log, escolher um local para salvar os resultados dos angulos pitch e roll e iniciar o processamento dos dados. Tarefa versionada em branch main com tags de releases.

Como foi realizada esta tarefa:


Tecnologias Utilizadas:

    Qt para a interface gráfica e interface de desenvolvimento.
    C++ para a lógica de processamento.
    Git para o controle de versão.

Estrutura do Projeto:

    mainwindow.h: Contém a definição da classe MainWindow e suas funções e slots.
    mainwindow.cpp: Implementação das funções da classe MainWindow, incluindo os slots para os botões.
    ui_mainwindow.h: Interface gerada automaticamente pelo Qt para a MainWindow.
    Acelerometro.h e Acelerometro.cpp: Classes e métodos relacionados ao processamento dos dados do acelerômetro.

Como compilar e executar o software:

Pré-requisitos:

    Qt 6.0 ou maior. (Testado com Qt 6.7.0-beta1 e 6.6.1) qt.io/download
    Ubuntu 20.04
    Bibliotecas e ferramentas de desenvolvimento Qt e compilador (todos vem na instalação do Qt)
        QtCreator 12.0
        QtDesign Studio 4.3.2
        CMake 3.27.7
        Ninja 1.10.2
    Dependências necessárias
        sudo apt-get install build-essential libgl1-mesa-dev
     

Passos:

    Clonando o Repositório:
        Clone o repositório usando: git clone https://github.com/tiagostmec/acelerometer-test.git

    Configurando e Compilando no Qt Creator:
        Abra o Qt Creator.
        Selecione open project e navegue até o diretório clonado.
        Abra o CMakeLists.txt do projeto.
        Compile o projeto usando o Qt Creator. Use o Build de releases.
        Com isso o software está compilado e pode ser utilizado.

    Executando o Software:
        Após a compilação, execute o software diretamente do Qt Creator. (Run)
        Ou navegue até a pasta da build via prompt e utilize ./acelerometer

        
