# 🐶 Dogão

Dogão é uma biblioteca modular em desenvolvimento para facilitar o controle dos componentes da BitDogLab com o Raspberry Pi Pico W, utilizando FreeRTOS e MQTT. A ideia é que no futuro tudo o que você precise fazer seja importar `#include "dogao.h"` e pronto! Todos os componentes essenciais como Wi-Fi, MQTT, sensores e atuadores estarão prontos para uso com tarefas integradas usando FreeRTOS.

Atualmente a biblioteca está em estágio inicial, servindo também como documentação e aprendizado sobre como integrar e estruturar uma biblioteca robusta e reutilizável.

##  Objetivo

O objetivo é centralizar todo o controle da placa da BitDogLab em uma única interface, encapsulando o uso de:

- FreeRTOS
- Mosquitto (MQTT)
- Wi-Fi (com pico_cyw43)
- Sensores e atuadores
- Componentes com tarefas e semáforos

## Instalação do FreeRTOS

1. Acesse o site oficial: [https://www.freertos.org/](https://www.freertos.org/)

2. Faça o download do kernel.

3. Configure a variável de ambiente `FREERTOS_KERNEL_PATH` para que seu projeto possa localizar o kernel. Para isso, abra o PowerShell **como administrador** e execute o comando abaixo, substituindo pelo caminho onde você baixou o repositório:

```powershell
[System.Environment]::SetEnvironmentVariable("FREERTOS_KERNEL_PATH", "C:\caminho\para\FreeRTOS-Kernel", "User")
```

## Instalação do Mosquitto no Windows

1. Acesse o site oficial do Mosquitto em: [https://mosquitto.org/download](https://mosquitto.org/download)

2. Baixe o instalador do Windows (recomendado: “Windows Installer”) e execute-o. Durante a instalação, marque a opção para adicionar o Mosquitto ao `PATH` do sistema.

3. Após a instalação, abra o terminal (cmd ou PowerShell) e verifique se o Mosquitto foi instalado corretamente executando: mosquitto -v

stiver funcionando, o terminal mostrará a versão e indicará que está escutando na porta 1883.

4. Vá até a pasta onde o Mosquitto foi instalado, geralmente em: C:\Program Files\mosquitto

5. Altere um arquivo de configuração chamado `mosquitto.conf` com o conteúdo básico:

listener 1883
allow_anonymous true

6. Para iniciar o broker manualmente com esse arquivo de configuração, execute o seguinte comando dentro da pasta: mosquitto -c "C:\Program Files\mosquitto\mosquitto.conf" -v

## Contribuições

Esse projeto está em desenvolvimento e toda ajuda é bem-vinda! Você pode contribuir de várias formas:

- Abrindo **issues** com bugs, dúvidas ou sugestões
- Criando **pull requests** com correções, melhorias ou novos módulos
- Compartilhando ideias para tornar a biblioteca mais fácil de usar

### Como contribuir:

1. Faça um fork do repositório
2. Crie uma branch para sua funcionalidade ou correção: git checkout -b minha-contribuicao
3. Faça os commits com mensagens claras
4. Envie um pull request explicando o que foi alterado










