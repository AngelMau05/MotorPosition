clc
close all

%Subir datos
datos=importdata('Prueba2.xlsx');
entradacto=4*ones(3008,1);
voltaje=datos(:,2);
s=tf('s');
salidacto=voltaje;
plot(voltaje)

%Promedio Movil
m=50;
filtro=(1/m)*ones(1,m); %Promedio Movil
Entrada=entradacto;
Salida=salidacto;
Salida=conv(Salida,filtro);


figure,
plot (Salida)
hold on
plot(Entrada)
hold off

% %Funcion de transferencia Toolbox
TF=tf21;

%Discretizacion
tfd=c2d(TF,0.004);
figure,
step(4*tfd)
