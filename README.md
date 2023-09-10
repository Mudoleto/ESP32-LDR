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

Un modulo LDR es aquel que controla la sencibilidad ala luz de una foto resistencia gracias a un potenciometro que le ayudara a saber en cuanto a cuanto puede apagar y encender.

[![ADIYLDRSensor-Module-Tomson-Electronics-1200x1200.webp](https://i.postimg.cc/7P2R44bv/ADIYLDRSensor-Module-Tomson-Electronics-1200x1200.webp)](https://postimg.cc/pyPCQgDk)

Tengamos en cuenta las siguientes caracteristicas del modulo LDR, en la cual tendra tres pines/conectores que nos permitira operar con el.

A0 ---> Envia los datos analogicos ala placa ESP32 o la que el usuario este utilizando, es importante identificar en base al esquematico cuales son los puertos analogicos que nos permitira
capturar estos datos.

GND -- -> Es la tierra del dispositivo en la que tendra que conectar el GND del esp32 a ese pin.

VCC -- -> El modulo opera con una corriente de 3.3v a 5v por lo que es posible elegir entre estos dos, siempre y cuando no sobre pase el voltaje de lo que esta sugerido.

[![imagen.png](https://i.postimg.cc/g01KtwVx/imagen.png)](https://postimg.cc/HJ45VkPm)

Ademas este cuenta con un potenciometro, que sirve para ajustar la sencibilidad ala luz de la foto resistencia, si necesitas que su reaccion sea menor ala luz o mayor con un desarmador
podras ajustar esos valores.

--------------------------------------------------------------------------------------------------
Modulo Relay o Relevador

El modulo relay/relevador, funciona como un interruptor de paso sin embargo lo que lo hace diferente es que por dentro del encapsulado existe una bobina que al recibir voltaje este cierra o abre
unos platinos que permitiran el paso de corriente a algun dispositivo, tambien se les considera como "El estado de una señal", son conocidos por "NC" y "NA" que quiere decir NC (Normalmente cerrado) y 
NA (Normalmente abierto), a continuacion una tabla de estado que representa de mejor manera los tipos de estados existentes.

[![cuadro-estado-senal1.gif](https://i.postimg.cc/PxZ0Snwk/cuadro-estado-senal1.gif)](https://postimg.cc/CBhvKt7v)

Aclarado esto, el modulo relay/relevador, tiene estos dos en las borneras que se encuentran en el lado izquierdo del modulo con los pines de conexion apuntando ala derecha:

[![41dh-MBn-DNEL-AC-UF894-1000-QL80.jpg](https://i.postimg.cc/bryLk70g/41dh-MBn-DNEL-AC-UF894-1000-QL80.jpg)](https://postimg.cc/34qgHbc0)

Pero que es COM? COMUN, es donde se encontrara la corriente en un estado hasta que alguno de los anteriores mencionados se cumpla con una respectiva salida, a continuacion una imagen que explica mejor
lo anteriormente mencionado.

[![mod1rele-2-600x600.png](https://i.postimg.cc/BbFD8Nkp/mod1rele-2-600x600.png)](https://postimg.cc/tnX7wdXn)


--------------------------------------------------------------------------------------------------
Comencie definiendo el pin en el que LDR estara funcionando al igual con el revelador

Que serian:

[![imagen.png](https://i.postimg.cc/s2PNW4dV/imagen.png)](https://postimg.cc/94Mb5TQS)

Despues en el void setup, configuraremos los parametros para el monitor serial pueda obtener los datos del esp32, recordar que el ESP32 trabaja con 115200 baud, decirle con pinMode(el modo que trabajara
el pin) que el relevador sera OUTPUT(salida) y que tenga un espera de 1 segundo antes de comenzar

[![imagen.png](https://i.postimg.cc/JnrH7M51/imagen.png)](https://postimg.cc/VShkDyhT)

En caso de tener menor o mayor cantidad en el apartado del monitor serial en la parte superior derecha tendras una ventanilla en la cual podras configurar estos datos.

[![imagen.png](https://i.postimg.cc/cJ6cx7x9/imagen.png)](https://postimg.cc/TyMbQDWg)

Comenzando con el void loop, empezara leer los datos y almacenarlos en una variable llamda val, utilizando analogRead nos permitira leer de los pines analogicos los datos obtenidos para
asi despues pasar a la evaluacion de estos con ayuda de un condicional if else.

NOTA: [!] Los datos pueden variar pues es necesario que hagan la prueba de manera indivual del modulo LDR, en el inicio del README estara un simulador WokWi de como probarlo con todo y codigo.

Remontando lo anteriormente mencionado, esta seria la estructura que se estaria manejando.

[![imagen.png](https://i.postimg.cc/8CKfCxKM/imagen.png)](https://postimg.cc/XZ5YH10Y)

En el primer condicional, Si el valor es menor o igual a 0 quiere decir que tenemos iluminacion en la foto resistencia por lo tanto no mandara una señal al relevador para el paso de corriente
caso contrario si el LDR se le obstruye el paso de luz este enviara un dato mayor a 0 que quiere decir que no hay luz y por lo tanto encienda el relevador.

