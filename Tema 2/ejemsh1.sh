echo SUBSHELL
DIRACT=`pwd`
echo Directorio Actual $DIRACT
echo Cambiando directorio en el subshell ...
cd /etc/
echo Ahora estoy en el directorio `pwd`
cd
echo Ahora estoy en el directorio `pwd`

