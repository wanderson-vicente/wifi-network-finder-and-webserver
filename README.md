# wifi-network-finder-and-webserver
# Estudo sobre as Bibliotecas WiFi.h e WebServer.h
## Introdução
Este projeto tem como objetivo estudar e aprimorar as técnicas de uso das bibliotecas WiFi.h e WebServer.h no microcontrolador ESP32. O código busca todas as redes Wi-Fi com sinal em torno do ESP32 e apresenta as informações em uma página web local, hospedada no próprio ESP32 através de um servidor web.

## Componentes
* Microcontrolador ESP32
* Biblioteca WiFi.h para gerenciamento da conexão Wi-Fi
* Biblioteca WebServer.h para criação do servidor web

## Funcionamento
1. Conexão Wi-Fi: O ESP32 se conecta à rede Wi-Fi local utilizando as credenciais definidas no código.
2. Criação do Servidor Web: Um servidor web é criado na porta 80 utilizando a biblioteca WebServer.h.
3. Definição das Rotas: As rotas do servidor web são definidas, incluindo a rota raiz ("/").
4. Varredura de Redes Wi-Fi: Quando a rota raiz é acessada, o ESP32 realiza uma varredura das redes Wi-Fi em seu alcance.
5. Exibição das Informações: As informações das redes Wi-Fi encontradas, incluindo SSID, força do sinal e endereço MAC, são exibidas em uma página web.
6. Atualização do Servidor: O servidor web é atualizado continuamente para atender às requisições dos clientes.

## Código
O código é dividido em duas principais funções: setup() e loop().
* setup(): Inicializa a serial, configura o modo Wi-Fi, conecta-se à rede Wi-Fi local, obtém o endereço IP do ESP32 e define as rotas do servidor web.
* loop(): Atualiza o servidor web para atender às requisições dos clientes.
A função handleRoot() é responsável por gerar o conteúdo HTML da página web, exibindo as informações das redes Wi-Fi encontradas. A função getConnectedDevicesHtml() realiza a varredura das redes Wi-Fi e retorna o HTML formatado com as informações.
Observações
* O código utiliza as bibliotecas WiFi.h e WebServer.h para gerenciar a conexão Wi-Fi e criar o servidor web.
* As credenciais da rede Wi-Fi local devem ser definidas nas variáveis ssid e password.
* O servidor web é criado na porta 80.

# Autor
Wanderson Vicente
Data
04/07/2024
