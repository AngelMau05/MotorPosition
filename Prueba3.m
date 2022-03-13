clc
close all
%k=1
%Subir datos
datos=importdata('Prueba3.xlsx');
entradacto=0.1*ones(3069-39,1);
voltaje=datos(:,2);
s=tf('s');
salidacto=voltaje;
plot(voltaje)

%Promedio Movil
m=40;
filtro=(1/m)*ones(1,m); %Promedio Movil
Entrada=entradacto;
S=salidacto;
S=conv(S,filtro);
Salida=S(40:3069);

figure,
hold on
plot(Salida)
plot(Entrada)
hold off

% %Funcion de transferencia Toolbox
TF=(45.53*s^2 + 251.3*s + 1.924)/(s^4+2.135*s^3+3.891*s^2+3.532*s+1.498);

%Discretizacion
tfd=c2d(TF,0.004);
figure,
step(0.1*tfd)