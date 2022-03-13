clc
close all
clear
%Subir datos
datos=importdata('Prueba1.xlsx');
entradacto=4*ones(2653,1);
voltaje=datos(:,2);
s=tf('s');
salidacto=voltaje;
plot(voltaje)

%Promedio Movil
m=30;
filtro=(1/m)*ones(1,m); %Promedio Movil
Entrada=entradacto;
Entrada=conv(Entrada,filtro);
Salida=salidacto;
Salida=conv(Salida,filtro);


figure,
plot (Salida)
hold on
plot(Entrada)
hold off

%Funcion de transferencia Toolbox
TF=0.07363/(s^3+0.7647*s^2+0.3314*s+0.06577);

%Discretizacion
tfd=c2d(TF,0.008);
figure,
step(4*tfd)
