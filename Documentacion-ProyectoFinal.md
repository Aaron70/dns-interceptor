#  Tecnológico de Costa Rica

##  Escuela de Ingeniería en Computación

##  Redes (IC 7602)

##  Proyecto II

###  Valor: 30%

###  Segundo Semestre 2022

###  Integrantes de grupo:

* ### Aaron Vargas Valerin

* ### Ingrid Fernández Arce

* ### Daniel Barrantes Esquivel

* ### Adriana López Calderón

##  Instrucciones de cómo ejecutar el proyecto en linux(Ubuntu)

###  Pre requisitos:

Descargar o clonar los archivos del proyecto que se encuentra en el repositorio de Github

<[Aaron70/dns-interceptor (github.com)](https://github.com/Aaron70/dns-interceptor)>

> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Para más información sobre cómo clonar un repositorio de GitHub, ingresar al siguiente link:

https://docs.github.com/es/repositories/creating-and-managing-repositories/cloning-a-repository?platform=linux

###  Instrucciones de ejecución:

Ir a la carpeta donde se guardó o clonó los documentos del Proyecto

Abrir la carpeta llamada “dns-interceptor”. En ella se encontrará los siguientes archivos

![](https://lh3.googleusercontent.com/bW26dhb6Z0SPatai8frbD2AE7P8ArQJaIO0_4e35vhUF5fJEFgnuBATLi9KtTqPgLJT35oS8XKLJhHBbvj8uKWPh-zurTxvBNnY1Qtr-1rMNmTMtFdCNtEIK39EpxuORjlKT83UI7Ne0n1jlboTJ7iqWdrZia7JhnZh5ZBACYPZCwp4SJPW5aOcXHzBQNQ)

>Dar click derecho y seleccionar la opción “Open in terminal”

![](https://lh5.googleusercontent.com/QY11aWF0EdH81-ZvWNopMGRI_3ZTs7ag0wbCK9d_8rRysaX-jIN54X0l5IykR5YlViFMF4m_EEPP5mb_auJoeMBwkHfRrk2uYKvCIr0-LTQsq2PDgn8Yiey34L2uG-QxWQ-Qwo7mB3LrTaw64G24LpfaadU4At26No5VV1R3Sj17JV2DiRMcuzYjMiOnWg)

Deberá aparecer una ventana similar a la siguiente

![](https://lh5.googleusercontent.com/gAGNlDvtJZZ8Hby-YxHovi3tNZy4QiHesupvBxDYytT7gDKSyl2X3vLScYyumeFP8s2D6HIzU0QsdorwfwD9C8Pfg5Mo1tGC_cZ6SiQNgvZV3EI4A64tzEKBeSIUGel0_mU5F7Iy_wtaDuNnHKbugQGjxQ5QFWQQk1Mn4qQwc2Ua7HpS9DoY4zkhoNVX3w)


Ejecutar el archivo “./start.sh” 
![](https://lh3.googleusercontent.com/RrXuk8yr3s_kB_Egedl1CiE2NYut8GZG5R0Y2rr_jfaKF34GM5HyHd9aW6S9_5zGZq6PNCYmF1MaVN6uiF26h5WOR454gHCkH3-ZK7eLIyJmxuv7sUaXlM5ZYLHbvHDZBAyQsIfS9dvGz3-RtocLBPpoB9chJvOFCj4qQ2bT2ag07hUT8dbWBkIWgylFXA)

Luego se empezará a construir los componentes necesarios

##  Instalaciones necesarias
### Kubectl
Para saber cómo instalarlo, ingresar al siguiente link:
[Install and Set Up kubectl on Linux | Kubernetes](https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/)

### Minikube
Para saber cómo instalarlo, ingresar al siguiente link:
[minikube start | minikube (k8s.io)](https://minikube.sigs.k8s.io/docs/start/)

### Helmchart
Para saber cómo instalarlo, ingresar al siguiente link:
[Helm | Installing Helm](https://helm.sh/docs/intro/install/)

### Docker 
Para saber cómo instalarlo, ingresar al siguiente link:
[Install on Ubuntu | Docker Documentation](https://docs.docker.com/desktop/install/ubuntu/)
## Pruebas de funcionalidad
1. Prueba del DNS al resolver www.google.com
![](https://lh5.googleusercontent.com/K7wabUjUoQVXKYzPZ2BqeZVoz_3ChC4IAXzBIFLF5UJ_OYTkPrFAv6ZiU6WeMG1HcqxFt1zswUVOokfcJZAHalb1Art772-Mh-8DCrfQYIezM7HQKxi2U6CV5tx3fxwYAD9HKM9G7_lYnPMj_UMRiPMJhJWlnd1xCTKmZHFGlJDkc5foZjVklzZPEjstDw)![](https://lh6.googleusercontent.com/0VnAFk13vgOiBPRW3oVZ_OqsGJExAqamZ6d034oob-ImKZGUO2RwUziSRW-GC1QMbCuUiqntOSMg68hTmFO86LCJC7lyveJX2EPix-2vqJvVI5byqiI6BP5EkXQO78neKDtVsXGoOZT364d50pdzGuv32pMSPsElW7SwAmTag0obei-F6yyh_r12rGEeNw)
2. Prueba del DNS al resolver www.youtube.com
**![](https://lh4.googleusercontent.com/QXfHeBrqwHz0SIpPzTirtZsiVIEfWK_akOgndIdVTlvNJhz0tZKh0EJMLNSFogInnlaJOHUNS90jZ0pIP3g74ojPCcIQq9RRGIX3yHigzkt0BY3LZRE__UxyiTX7dhZ2AJVacCYeipNqESJySzWYRoXvKKyUbdE0nXdDOc_WU9X6rVQQMXMWxEbxeXDpCg)![](https://lh4.googleusercontent.com/ORpl5CbN1kvcVJD44zrt9CN5WF6pxk17GY8KOF1ZtCHmKarNLk6HBplonXPk72hZtjbrmLM9VePnzQG4mAPeFtRmI46YNBiSRR7nSI_ALPjHOiyDCLJOeDYYEuX0_eexe-OvMSIlv6-XwI_Ex8dyuD2sGBWbr7xnw5xzGFNq28P0ye5XVhRwXLulh7iMjQ)**
2. Prueba del DNS al resolver www.nacion.com
**![](https://lh5.googleusercontent.com/eTPatlEzaRH3d1TgagRiWDCkLoMijbTLbBW36WPx8LaZrZQFYuvfqzjWd0ecZmA7iojQxUsM1OK-RxWzonAIAVaDWdyUONP-TMSmbqrrFt6knmZ7b5G8BbICfsyjMT42BVD9LrlmLdMQ4ZfO3PtQJUZMnQ6ole8xuL8qidm096O9iYW78pDkFVl4-Psesg)![](https://lh3.googleusercontent.com/MV9nO8-S5-KXzbELPZDFxtUjZkaarqaanLw2voVyiAwv4KOhot3yCpxEDNFWgfDe3H_-N83x-uRK6_wb1E5478-vD5m56oi-PiS7NGJS6kSSnk-JKEAdwvvwWFhq5EcGnPWYEVRjSsqzqEBp9y6Ak-2nFOu16Ol8Wsn2CRXgLZ85OAc-aagpi6Ktpz7eJw)**
##  Recomendaciones


* Al iniciar se debe asegurar tener todos los paquetes y dependencias necesarias instaladas correctamente

* Instalar aquellas dependencias faltantes

* La mejor manera de crear archivos JSON o la estructura de uno en C es con la librería llamada Jansson.

* Si se usa la librería Jansson en C no hay que olvidar usar la bandera -ljansson a la compilar el archivo con gcc.

* Para trabajar con curl en C y hacer peticiones HTTPS, la manera más sencilla es usar la librería Libcurl.

* Si se usa la librería Libcurl en C no hay que olvidar usar la bandera -lcurl a la hora de compilar.

* Al usar la Libcurl y crear la función no hay que olvidar configurarlo para que pueda trabajar con JSON y configurar la función añadiendo al header "Accept: application/json" y "Content-Type: application/json".

* Si se instala elascticsearch en una pc sin usar contenedor no hay que olvidar que por defecto usa un 50 % de RAM.

* Antes de instalar elascticsearch no hay que olvidar instalar JAVA.

* Si se está trabajando con una estructura de NSLOOKUP y se tiene un array de bytes, para poder interpretar esos bytes y verlos de una manera legible se podría usar DNSRECORD en python de la librería DNSLIB.

* Para hacer codificación a base 64 en python la manera más fácil es por medio de la librería ( base64 ).

* Si se reserva memoria MALLOC no hay que olvidar incluir el carácter '\0' dado que si se calcula mal el tamaño daría un error en la reserva del bloque de memoria.


##  Conclusiones

- La librería Jansson realmente resulta muy útil para trabajar JSON en C, realmente pensábamos que iba ser más difícil dado el tipo de lenguaje de programación sin embargo con esta herramienta resultó más fácil.

- La librería Libcurl al usarla también resultó de mucha utilidad, las peticiones se recibieron y se enviaron de una manera muy sencilla gracias a esta herramienta.

- Poder recibir el paquete de la manera correcta del NSLOOKUP resultó todo un reto dado que tuvimos que hacer muchas pruebas de lo recibido, y así poder armar la estructura correspondiente de un paquete dado el RFC2929.

- El usar elascticsearch nos resultó muy interesante. Es una herramienta que no conocíamos por lo que al trabajar con él nos pareció una herramienta muy potente y muy útil, sin embargo el consumo de la memoria RAM al inicio nos pareció algo sorprendente, dado que no creíamos que consumiera tanto.

- Todos los miembros del equipo trabajamos bajo el entorno Linux ( Debian y Ubuntu ) por lo que muchas cosas se nos facilitó dado que teníamos algo de experiencia con la terminal de este sistema operativo, sin embargo de igual manera muchas veces aparecieron retos que tuvimos que ir solucionando por lo que nos llevó a una curva de aprendizaje en Linux, fortaleciendo nuestros conocimientos en el mismo.

- Las documentaciones de muchas herramientas eran muy útiles, por lo que nos brindó un mejor conocimiento de algunas usadas, de igual manera muchos foros de internet nos aportaban muchas ideas o nos brindaban mucha ayuda en distintas dificultades que se nos presentaron en el momento.

- Docker es una herramienta muy utilizada en el mercado, trabajar con él nos ayudó a fortalecer nuestros conocimientos y tener un mejor conocimiento de las herramientas utilizadas en el ámbito laboral.

- El poder levantar una imagen de docker con Ubuntu por ejemplo, nos ayudó a hacer muchas pruebas a la hora de trabajar, ayudándonos a no hacerlas en la máquina física, por lo que si aparecía algún error no habría ningún problema, por lo que fue una herramienta de gran utilidad para este proyecto, y estamos seguros que para próximos también nos ayudará.

- Para crear el API con el método POST en python se usó FLASK, resultó ser muy sencillo una vez leyendo la documentación e información general en distintos sitios de internet, por lo que resultó ser de gran utilidad aprender cómo usar flask con python.

- Helm Charts y Kubernetes son herramientas que nos parecieron muy útiles, ningún miembro del equipo había trabajado nunca con ninguno de los 2, por lo que tuvo una curva de aprendizaje en cada uno de nosotros, realmente nos pareció bastante fascinante como con estas herramientas se pueden automatizar muchas haciendo distintas configuraciones con cada uno.
