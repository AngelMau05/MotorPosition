clc
close all
%k=75
%Subir datos
datos=importdata('Prueba4.xlsx');
entradacto=4*ones(2869,1);
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
Salida=S(1:2869);

figure,
hold on
plot(Salida)
plot(Entrada)
hold off

% %Funcion de transferencia Toolbox
TF=(0.04886*s^4 - 0.4019*s^3 + 1.292*s^2 - 0.8281*s + 2.423)/(s^5 + 2.566*s^4 + 6.639*s^3 + 8.486*s^2 + 6.977*s + 2.502);

%Discretizacion
tfd=c2d(TF,0.004);
figure,
step(4*tfd)