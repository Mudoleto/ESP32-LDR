# ESP32-LDR
Proyecto numero 1: Sistema de iluminacion por foto resistencia

#Autor @Mudoleto (Sergio Sandoval)

[![Arduino.png](https://i.postimg.cc/NMtdfqZb/Arduino.png)](https://postimg.cc/1gWGJTmN)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Sencillo, controlar el flujo de corriente de un foco mediante una foto resistencia y un relevador utilizando la placa de programacion ESP32 Dev

Siluacion del uso del modulo LDR: https://wokwi.com/projects/374191164112641025

Simulacion del uso del modulo de relavador: https://wokwi.com/projects/374193750162207745

==================================================================

Simulacion de proyecto LDR: https://wokwi.com/projects/374193801290775553

--------------------------------------------------------------------------------------------------------

Materiales necesarios: 

1.- ESP32.  
2.- Modulo LDR.    
3.- Modulo relevador.   
4.- Placa protoboard.  
5.- Cable macho/macho.  
6.- Diodos led's o foco (opcional).  
7.- socket (opcional).  
8.- Resistencia 330 Ohms.  

--------------------------------------------------------------------------------------------------
LDR datasheet

[![Photo-resistor-LDR-Light-Sensor-Module-3-Pin.png](https://i.postimg.cc/W4N8JL24/Photo-resistor-LDR-Light-Sensor-Module-3-Pin.png)](https://postimg.cc/68PnDP4s)

Tengamos en cuenta las siguientes caracteristicas del modulo LDR, en la cual tendra tres pines/conectores que nos permitira operar con el

D0 TTL ---> Envia los datos analogicos ala placa ESP32 o la que el usuario este utilizando, es importante identificar en base al esquematico cuales son los puertos analogicos que nos permitira
capturar estos datos.


--------------------------------------------------------------------------------------------------
Empezaremos primero en ver el funcionamiento de un modulo LDR

Comenzamos con definir el pin en el que estaremos conectando nuestro modulo LDR las cuales son

