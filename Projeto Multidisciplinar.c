#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define SIZE 100

typedef struct{
    char nome[SIZE];
    int credencial;
    int senha;
} Usuario;

void salvarConversao(float resp);
void convertmassa(int a,float b,int i);
void menumassa(int j);
void convertvelocidade(int a,float b,int i);
void menuvelocidade(int j);
void converttemperatura(int a,float b,int i);
void menutemperatura(int j);
void convertcomprimento(int a,float b,int i);
void menucomprimento(int j);
void converttempo(int a,float b,int i);
void menutempo(int j);
void convertpressao(int a,float b,int i);
void menupressao(int j);
void convertarea(int a,float b,int i);
void menuarea(int j);
void convertvolume(int a,float b,int i);
void menuvolume(int j);
void convertenergiamecanica(int a, float b,int i);
void menuenergiamecanica(int j);
void menuprincipal2(int i,int j);
void menuprincipal1(void);
void leitor(void);
void login(Usuario *cad);
void multiplo(void);
float recursao(float x,float y);

int     TAM=2, test=0, linhas=0;
float   *p=NULL;
float   arquivo[100];

int main(){
    setlocale(LC_ALL, "Portuguese");
    system("color 0E");
    p=(int*)calloc(1,sizeof(int));
    Usuario cad;
    int aux=0;
    printf("FAÇA SEU CADASTRO:");
    printf("\nDigite seu nome: ");
    fgets(cad.nome,SIZE,stdin);
    fflush(stdin);
    printf("Digite sua credencial: ");
    scanf("%i",&cad.credencial);
    fflush(stdin);
    printf("Digite sua senha: ");
    scanf("%i",&cad.senha);
    fflush(stdin);
    system("cls");
    login(&cad);
    if(test!=1){
        system("cls");
        printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
        printf("\n\n\tSair:");
        printf("\n\t[0] ENCERRAR");
        printf("\n\t[1] VER HISTÓRICO DE CONVERSÕES");
        printf("\n\tOpção: ");
        scanf("%i",&aux);
        fflush(stdin);
        if(aux==1){
            printf("\n\t\tHISTÓRICO:");
            for(int i=0;i<TAM-2;i++){
                printf("\n\t\t%f",p[i]);
            }
        }
    }
    Sleep(3000);
    printf("\n\n\n========================================================================================================================");
    printf("\n================================================== PROGRAMA ENCERRADO ==================================================");
    printf("\n========================================================================================================================");
    Sleep(5000);
    printf("\n\n\n\n\n\n\n==================================================== DESENVOLVEDORES ===================================================");
    printf("\n\n\tAnne Caroline Prodócimo");
    printf("\n\tGabriel Joshua Rodrigues");
    printf("\n\tHugo Vieira Chagas Rabelo");
    printf("\n\tJoão Vítor Fernandes da Costa");
    printf("\n\tVitor Arcolini Veine\n\n");
    free(p);
    return 0;
}

void login(Usuario *cad){
    int senha=0;
    printf("========================================================================================================================");
    printf("\a\n==================================== BEM-VINDO AO SOFTWARE DE CONVERSÃO DE UNIDADES ====================================");
    printf("\n========================================================================================================================");
    printf("\nUsuário: %s",cad->nome);
    printf("Credencial: %i",cad->credencial);
    printf("\nDigite sua senha: ");
    scanf("%i",&senha);
    if(senha==cad->senha){
        system("cls");
        menuprincipal1();
    }else{
        printf("\n\tSENHA INCORRETA.\n\tTENTE NOVAMENTE!");
        Sleep(4000);
        system("cls");
        login(cad);
        if(senha==cad->senha){
            system("cls");
            menuprincipal1();
        }
    }
}
void leitor(void){
    test=1;
    int j=0;
    char ARQUIVO[] = "C:\\Users\\T-Gamer\\Desktop\\arq.txt";
    char MODO[] = "r";
    FILE *fd = NULL;
    fd = fopen(ARQUIVO, MODO);
    if( fd == NULL ){
        printf("\nErro na abertura do arquivo.");
        exit(1);
    }
    float i=0;
    while ( fscanf(fd,"%f", &i) != EOF){
        linhas++;
        if(linhas>=100){
            printf("\nARQUIVO MUITO EXTENSO, NÚMERO MÁXIMO DE CONVERSÕES: 100");
            Sleep(1000);
            fclose(fd);
            exit(1);
        }
        arquivo[j]=i;
        j++;
    }
    menuprincipal2(arquivo[0],arquivo[1]-arquivo[2]);
    fclose(fd);
}
void menuprincipal1(void){
    int i;
    int resp = 0;
    printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
    printf("\n\nEscolha o tipo de conversão desejada:\n");
    printf("\n1) CONVERSÃO PADRÃO");
    printf("\n2) CONVERSÃO A PARTIR DE ARQUIVO");
    printf("\n\nOpção: ");
    scanf("%d",&i);
    switch(i){
        case 1:{
            system("cls");
            menuprincipal2(0,0);
            break;
        }
        case 2:{
            system("cls");
            leitor();
            break;
        }
        default:{
            printf("\n\tOpção não reconhecida.\n\tTENTE NOVAMENTE!");
            Sleep(4000);
            system("cls");
            menuprincipal1();
        }
    }
}
void menuprincipal2(int i,int j){
    if(test==0){
        printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
        printf("\n\nCONVERSÃO PADRÃO:");
        printf("\n\n\tEscolha conversão desejada: \n");
        printf("\n\t1) COMPRIMENTO");
        printf("\n\t2) MASSA");
        printf("\n\t3) TEMPO");
        printf("\n\t4) ÁREA");
        printf("\n\t5) ENERGIA MECÂNICA");
        printf("\n\t6) PRESSÃO");
        printf("\n\t7) TEMPERATURA");
        printf("\n\t8) VELOCIDADE");
        printf("\n\t9) VOLUME");
        printf("\n\t10) MÚLTIPLOS");
        printf("\n\n\tOpção: ");
        scanf("%d",&i);
    }
    switch(i){
        case 1:{
            system("cls");
            menucomprimento(j);
            break;
        }
        case 2:{
            system("cls");
            menumassa(j);
            break;
        }
        case 3:{
            system("cls");
            menutempo(j);
            break;
        }
        case 4:{
            system("cls");
            menuarea(j);
            break;
        }
        case 5:{
            system("cls");
            menuenergiamecanica(j);
            break;
        }
        case 6:{
            system("cls");
            menupressao(j);
            break;
        }
        case 7:{
            system("cls");
            menutemperatura(j);
            break;
        }
        case 8:{
            system("cls");
            menuvelocidade(j);
            break;
        }
        case 9:{
            system("cls");
            menuvolume(j);
            break;
        }
        case 10:{
            system("cls");
            multiplo();
            break;
        }
        default:{
            printf("\n\tOpção não reconhecida.\n\tTENTE NOVAMENTE!");
            Sleep(4000);
            system("cls");
            menuprincipal2(i,j);
        }
    }
}

void convertcomprimento(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//km >> in
            if(test==0){
                printf("\n\t%.6f km --> %.6f in",b, b * 39370.1);
                p[i]= b * 39370.1;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 39370.1);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f km --> %.6f in",arquivo[i],(arquivo[i]* 39370.1));
            }
            break;
        }
        case -6:{//km >> yd
            if(test==0){
                printf("\n\t%.6f km --> %.6f yd",b,b * 1093.61);
                p[i]= b * 1093.61;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1093.61);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f km --> %.6f yd",arquivo[i],(arquivo[i]* 1093.61));
            }
            break;
        }
        case -14:{//km >> mi
            if(test==0){
                printf("\n\t%.6f km --> %.6f mi",b,b / 1.609);
                p[i]= b / 1.609;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1.609);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f km --> %.6f mi",arquivo[i],(arquivo[i]/ 1.609));
            }
            break;
        }
        case 2:{//in >> km
            if(test==0){
                printf("\n\t%.6f in --> %.6f km",b, b / 39370.1);
                p[i]= b / 39370.1;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 39370.1);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f in --> %.6f km",arquivo[i],(arquivo[i] / 39370.1));
            }
            break;
        }

        case -4:{//in >> yd
            if(test==0){
                printf("\n\t%.6f in --> %.6f yd",b, b / 36);
                p[i]= b / 36;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 36);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f in --> %.6f yd",arquivo[i],(arquivo[i] / 36));
            }
            break;
        }

        case -12:{//in >> mi
            if(test==0){
                printf("\n\t%.6f in --> %.6f mi",b, b / 63360);
                p[i]= b / 63360;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 63360);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f in --> %.6f mi",arquivo[i],(arquivo[i] / 63360));
            }
            break;
        }

        case 6:{//yd >> km
            if(test==0){
                printf("\n\t%.6f yd --> %.6f km",b, b / 1093.61);
                p[i]= b / 1093.61;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1093.61);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f yd --> %.6f km",arquivo[i],(arquivo[i]/ 1093.61));
            }
            break;
        }

        case 4:{//yd >> in
            if(test==0){
                printf("\n\t%.6f yd --> %.6f in",b, b * 36);
                p[i]= b * 36;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 36);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f yd --> %.6f in",arquivo[i],(arquivo[i]* 36));
            }
            break;
        }

        case -8:{//yd >> mi
            if(test==0){
                printf("\n\t%.6f yd --> %.6f mi",b, b / 1760);
                p[i]= b / 1760;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1760);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f yd --> %.6f mi",arquivo[i],(arquivo[i] / 1760));
            }
            break;
        }

        case 14:{//mi >> km
            if(test==0){
                printf("\n\t%.6f mi --> %.6f km",b, b * 1.609);
                p[i]= b * 1.609;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1.609);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f mi --> %.6f km",arquivo[i],(arquivo[i]* 1.609));
            }
            break;
        }

        case 12:{//mi >> in
            if(test==0){
                printf("\n\t%.6f mi --> %.6f in",b,b * 63360);
                p[i]= b * 63360;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 63360);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f mi --> %.6f in",arquivo[i],(arquivo[i] * 63360));
            }
            break;
        }

        case 8:{ //mi >> yd
          if(test==0){
                printf("\n\t%.6f mi --> %.6f yd",b, b * 1760);
                p[i]= b * 1760;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1760);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE COMPRIMENTO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f mi --> %.6f yd",arquivo[i],(arquivo[i]* 1760));

            }
            break;
        }

        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menucomprimento(0);
    }
}
void menucomprimento(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO DE COMPRIMENTO:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Quilômetros\t[km]");
            printf("\n\t4) Polegadas\t[in]");
            printf("\n\t8) Jardas \t[yd]");
            printf("\n\t16) Milhas\t[mi]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertcomprimento(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertcomprimento(j,1,0);
    }
}

void convertmassa(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//grama >>libra
            if(test==0){
                printf("\n\t%.6f g --> %.6f lb",b,(b * 0.0022046));
                p[i]=b * 0.0022046;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*0.0022046);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f g --> %.6f lb",arquivo[i],(arquivo[i]*0.0022046));
            }
        break;
        }
        case -6:{//grama >>onça
            if(test==0){
                printf("\n\t%.6f g --> %.6f oz",b,(b / 28.35));
                p[i]=b / 28.35;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 28.35);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f g --> %.6f lb",arquivo[i],(arquivo[i]/ 28.35));
            }
        break;
        }
        case -14:{//grama >>Arroba
            if(test==0){
                printf("\n\t%.6f g --> %.6f @",b,(b/14688));
                p[i]=b/14688;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/14688);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f g --> %.6f lb",arquivo[i],(arquivo[i]/14688));
            }
        break;
        }
        case 2:{//Libra >>grama
            if(test==0){
                printf("\n\t%.6f lb --> %.6f g",b,(b * 454));
                p[i]=b * 454;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 454);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f lb --> %.6f g",arquivo[i],(arquivo[i]*454));
            }
        break;
        }
        case -4:{//libra >>onça
            if(test==0){
                printf("\n\t%.6f lb --> %.6f oz",b,(b*16));
                p[i]=b*16;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*16);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f lb --> %.6f oz",arquivo[i],(arquivo[i]*16));
            }
        break;
        }
        case -12:{//libra >>arroba
            if(test==0){
                printf("\n\t%.6f lb --> %.6f @",b,(b*33.069));
                p[i]=b*33.069;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*33.069);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f lb --> %.6f @",arquivo[i],(arquivo[i]*33.069));
            }
        break;
        }
        case 6:{//Onça >>Grama
            if(test==0){
                printf("\n\t%.6f oz --> %.6f g",b,(b*28.35));
                p[i]=b*28.35;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*28.35);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f oz --> %.6f g",arquivo[i],(arquivo[i]*28.35));
            }
        break;
        }
        case 4:{//Onça >>libra
            if(test==0){
                printf("\n\t%.6f oz --> %.6f lb",b,(b/16));
                p[i]=b/16;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/16);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f oz --> %.6f lb",arquivo[i],(arquivo[i]/16));
            }
        break;
        }
        case -8:{//Onça >> Arroba
            if(test==0){
                printf("\n\t%.6f oz --> %.6f @",b,(b/518.139));
                p[i]=b/518.139;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/518.139);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f oz --> %.6f @",arquivo[i],(arquivo[i]/518.139));
            }
        break;
        }
        case 14:{//Arroba >> grama
            if(test==0){
                printf("\n\t%.6f @ --> %.6f g",b,(b*14689));
                p[i]=b*14689;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*14689);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f @ --> %.6f g",arquivo[i],(arquivo[i]*14689));
            }
        break;
        }
        case 12:{//Arroba >>libra
            if(test==0){
                printf("\n\t%.6f @ --> %.6f lb",b,(b*39.3553));
                p[i]=b*39.3553;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                salvarConversao(b*39.3553);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f @ --> %.6f lb",arquivo[i],(arquivo[i]*39.3553));
            }
        break;
        }
        case 8:{//Arroba >> Onça
            if(test==0){
                printf("\n\t%.6f @ --> %.6f oz",b,(b *518.139));
                p[i]=b * 518.139;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*518.139);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE MASSA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f @ --> %.6f oz",arquivo[i],(arquivo[i]*518.139));
            }
        break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menumassa(0);
    }
}
void menumassa(int j){
    system("cls");
    int a,b,d=1,e=0,i=0, k=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO DE MASSA:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Grama\t[g]");
            printf("\n\t4) Libra\t[lb]");
            printf("\n\t8) Onça \t[oz]");
            printf("\n\t16) Arroba\t[@]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertmassa(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertmassa(j,1,0);
    }
}

void converttempo(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//hora >> decada
            if(test==0){
                printf("\n\t%.6f h --> %.6f década(s)",b, b / 87600);
                p[i]= b / 87600;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 87600);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f h --> %.6f década(s)",arquivo[i],(arquivo[i]*(b / 87600)));
            }
            break;
        }
        case -6:{//hora >> dia
            if(test==0){
                printf("\n\t%.6f h --> %.6f dia(s)",b, b / 24);
                p[i]= b / 24;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 24);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f h --> %.6f dia(s)",arquivo[i],(arquivo[i] / 24));

            }
            break;
        }
        case -14:{//hora>>seculo
            if(test==0){
                printf("\n\t%.6f h --> %.6f século(s)",b, b / 876000);
                p[i]= b / 876000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 876000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f h --> %.6f século(s)",arquivo[i],(arquivo[i] / 876000));
            }
            break;
        }
        case 2:{//decada>> hora
            if(test==0){
                printf("\n\t%.6f década(s) --> %.6f h",b, b * 876000);
                p[i]= b * 876000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 876000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f década(s) --> %.6f h",arquivo[i],(arquivo[i] * 876000));
            }
            break;
        }
        case -4:{//decada>>dia
            if(test==0){
                printf("\n\t%.6f década(s) --> %.6f dia(s)",b, b * 3650);
                p[i]= b * 3650;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 3650);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f década(s) --> %.6f dia(s)",arquivo[i],(arquivo[i] * 3650));
            }
            break;
        }
        case -12:{//decada>>seculo
            if(test==0){
                printf("\n\t%.6f década(s) --> %.6f século(s)",b, b / 10);
                p[i]= b / 10;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 10);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f década(s) --> %.6f século(s)",arquivo[i],(arquivo[i] / 10));
            }
            break;
        }
        case 6:{//dia>>hora
            if(test==0){
                printf("\n\t%.6f dia(s) --> %.6f h",b, b * 24);
                p[i]= b * 24;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 24);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f dia(s) --> %.6f h",arquivo[i],(arquivo[i]* 24));
            }
            break;
        }
        case 4:{//dia>>decada
            if(test==0){
                printf("\n\t%.6f dia(s) --> %.6f década(s)",b, b / 3650);
                p[i]= b / 3650;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 3650);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f dia(s) --> %.6f década(s)",arquivo[i],(arquivo[i] / 3650));
            }
            break;
        }
        case -8:{//dia>>seculo
            if(test==0){
                printf("\n\t%.6f dia(s) --> %.6f século(s)",b, b / 36500);
                p[i]= b / 36500;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 36500);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f dia(s) --> %.6f século(s)",arquivo[i],(arquivo[i] / 36500));
            }
            break;
        }
        case 14:{//seculo>>hora
            if(test==0){
                printf("\n\t%.6f século(s) --> %.6f h",b, b * 876000);
                p[i]= b * 876000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);

                if(aux==1){
                    salvarConversao(b * 876000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f século(s) --> %.6f h",arquivo[i],(arquivo[i] * 876000));
            }
            break;
        }

        case 12:{//seculo>>decada
             if(test==0){
                printf("\n\t%.6f século(s) --> %.6f década(s)",b, b * 10);
                p[i]= b * 10;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 10);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f século(s) --> %.6f década(s)",arquivo[i],(arquivo[i] * 10));
            }
            break;
        }
        case 8:{ //seculo>>dia
            if(test==0){
                printf("\n\t%.6f século(s) --> %.6f dia(s)",b, b * 36500);
                p[i]= b * 36500;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 36500);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f século(s) --> %.6f dia(s)",arquivo[i],(arquivo[i]* 36500));
            }
            break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menutempo(0);
    }
}
void menutempo(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO DE TEMPO:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Horas\t[h]");
            printf("\n\t4) Décadas\t");
            printf("\n\t8) Dias \t");
            printf("\n\t16) Séculos\t");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            converttempo(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        converttempo(j,1,0);
    }
}

void convertarea(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//m^2 >> hc
            if(test==0){
                printf("\n\t%.6f m² --> %.6f ha",b,(b / 10000));
                p[i]=b / 10000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 10000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m² --> %.6f ha",arquivo[i],(arquivo[i] / 10000));
            }
            break;
        }
        case -6:{// m^2 >> acre
            if(test==0){
                printf("\n\t%.6f m² --> %.6f acre(s)",b,(b / 4047));
                p[i]=b / 4047;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 4047);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m² --> %.6f acre(s)",arquivo[i],(arquivo[i]/ 4047));
            }
            break;
        }
        case -14:{// m^2 >> pol^2
            if(test==0){
                printf("\n\t%.6f m² --> %.6f in²",b,(b * 1550));
                p[i]=b * 1550;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1550);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m² --> %.6f in²",arquivo[i],(arquivo[i]* 1550));
            }
            break;
        }
        case 2:{//hc >> m^2
            if(test==0){
                printf("\n\t%.6f ha --> %.6f m²",b,(b * 10000));
                p[i]=b * 10000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 10000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ha --> %.6f m²",arquivo[i],(arquivo[i]* 10000));
            }
            break;
        }
        case -4:{// hc >> acre
            if(test==0){
                printf("\n\t%.6f ha --> %.6f acre(s)",b,(b * 2.471));
                p[i]=b * 2.471;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 2.471);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ha --> %.6f acre(s)",arquivo[i],(arquivo[i]* 2.471));
            }
            break;
        }
        case -12:{// hec >> pol^2
            if(test==0){
                printf("\n\t%.6f ha --> %.6f in²",b,(b * 0.000000155));
                p[i]=b * 0.000000155;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 0.000000155);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ha --> %.6f in²",arquivo[i],(arquivo[i]* 0.000000155));
            }
            break;
        }
        case 6:{// acre >> m^2
            if(test==0){
                printf("\n\t%.6f acre(s) --> %.6f m²",b,(b * 4047));
                p[i]=b * 4047;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 4047);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f acre(s) --> %.6f m²",arquivo[i],(arquivo[i]* 4047));
            }
            break;
        }
        case 4:{// acre >> hc
            if(test==0){
                printf("\n\t%.6f acre(s) --> %.6f ha",b,(b / 2.471));
                p[i]=b / 2.471;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 2.471);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f acre(s) --> %.6f ha",arquivo[i],(arquivo[i]/ 2.471));
            }
            break;
        }
        case -8:{// acre >> pol^2
            if(test==0){
                printf("\n\t%.6f acre(s) --> %.6f in²",b,(b * 0.00000627));
                p[i]=b * 0.00000627;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 0.00000627);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f acre(s) --> %.6f in²",arquivo[i],(arquivo[i]* 0.00000627));
            }
            break;
        }
        case 14:{// pol^2 >> m^2
            if(test==0){
                printf("\n\t%.6f in² --> %.6f m²",b,(b / 1550));
                p[i]=b / 1550;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1550);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f in² --> %.6f m²",arquivo[i],(arquivo[i]/ 1550));
            }
            break;
        }
        case 12:{// pol^2 >> hc
            if(test==0){
                printf("\n\t%.6f in² --> %.6f ha",b,(b / 0.000000155));
                p[i]=b / 0.000000155;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 0.000000155);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f in² --> %.6f ha",arquivo[i],(arquivo[i]/ 0.000000155));
            }
            break;
        }
        case 8:{// pol^2 >> acre
            if(test==0){
                printf("\n\t%.6f in² --> %.6f acre(s)",b,(b / 0.00000627));
                p[i]=b / 0.00000627;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 0.00000627);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f in² --> %.6f acre(s)",arquivo[i],(arquivo[i] / 0.00000627));
            }
            break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menuarea(0);
    }
}
void menuarea(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO PARA ÁREA:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Metros quadrados\t[m²]");
            printf("\n\t4) Hectares\t\t[ha]");
            printf("\n\t8) Acres\t");
            printf("\n\t16) Polegadas quadradas\t[in²]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertarea(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertarea(j,1,0);
    }
}

void convertenergiamecanica(int a, float b,int i){
    int aux=0;
    switch (a){
        case -2:{//joule>>Quilocaloria
            if(test==0){
                printf("\n\t%.6f J --> %.6f kcal",b,(b/4184));
                p[i]=(b/41846);
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/4184);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f J --> %.6f kcal",arquivo[i],(arquivo[i]/4184));
            }
            break;
        }
        case -6:{//joule>>Watt-hora
            if(test==0){
                printf("\n\t%.6f J --> %.6f Wh",b,(b/3600));
                p[i]=(b/3600);
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/3600);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f J --> %.6f Wh",arquivo[i],(arquivo[i]/3600));
            }
            break;
        }
        case -14:{//joule>>pé libra força
            if(test==0){
                printf("\n\t%.6f J --> %.6f ftlbf",b,(b/1356));
                p[i]=(b/1356);
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/1356);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f J --> %.6f ftlbf",arquivo[i],(arquivo[i]/1356));
            }
            break;
        }
        case 2:{//Quilocaloria>>Joule
            if(test==0){
                printf("\n\t%.6f kcal --> %.6f J",b,(b*4184));
                p[i]=(b*4184);
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*4184);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f kcal --> %.6f J",arquivo[i],(arquivo[i]*4.184));
            }
            break;
        }
        case -4:{//Quilocaloria>>Watt-hora
            if(test==0){
                printf("\n\t%.6f kcal --> %.6f Wh",b,(b *1.162));
                p[i]=b * 1.162;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*1.162);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f kcal --> %.6f Wh",arquivo[i],(arquivo[i]*1.162));
            }
            break;
        }
        case -12:{//Quilocaloria>>BTU
            if(test==0){
                printf("\n\t%.6f kcal --> %.6f ftlbf",b,(b * 3086));
                p[i]=(b * 3086);
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 3086);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f kcal --> %.6f ftlbf",arquivo[i],(arquivo[i]*3086));
            }
            break;
        }
        case 6:{//Watt-hora>>Joule
            if(test==0){
                printf("\n\t%.6f Wh --> %.6f J",b,(b * 3600));
                p[i]=b * 3600;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*3600);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Wh --> %.6f J",arquivo[i],(arquivo[i]*3600));
            }
            break;
        }
        case 4:{//Watt-hora>>Quilocaloria
            if(test==0){
                printf("\n\t%.6f Wh --> %.6f kcal",b,(b/1.162));
                p[i]=b/1.162;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/1.162);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Wh --> %.6f kcal",arquivo[i],(arquivo[i]/1.162));
            }
            break;
        }
        case -8:{//Watt-hora>>BTU
            if(test==0){
                printf("\n\t%.6f Wh --> %.6f ftlbf",b,(b*2655));
                p[i]=b*2655;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*2655);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Wh --> %.6f ftlbf",arquivo[i],(arquivo[i]*2655));
            }
            break;
        }
        case 14:{//ftlbf>>Joule
            if(test==0){
                printf("\n\t%.6f ftlbf --> %.6f J",b,(b*1356));
                p[i]=b*1356;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*1356);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ftlbf --> %.6f J",arquivo[i],(arquivo[i]*1356));
            }
            break;
        }
        case 12:{//ftlbf>>Quilocaloria
            if(test==0){
                printf("\n\t%.6f ftlbf --> %.6f kcal",b,(b/3086));
                p[i]=b/3086;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/3086);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ftlbf --> %.6f kcal",arquivo[i],(arquivo[i]/3086));
            }
            break;
        }
        case 8:{//ftlbf>>Watt-hora
            if(test==0){
                printf("\n\t%.6f ftlbf --> %.6f Wh",b,(b/2655));
                p[i]=b/2655;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/2655);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ftlbf --> %.6f Wh",arquivo[i],(arquivo[i]/2655));
            }
            break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menuenergiamecanica(0);
    }
}
void menuenergiamecanica(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO PARA ENERGIA MECÂNICA:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Joules\t\t[J]");
            printf("\n\t4) Quilocalorias\t[kcal]");
            printf("\n\t8) Watts-hora\t\t[Wh]");
            printf("\n\t16) Pé-libra força\t[ftlbf]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertenergiamecanica(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertenergiamecanica(j,1,0);
    }
}

void convertpressao(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//Pa >> Bar
            if(test==0){
                printf("\n\t%.6f Pa --> %.6f bar",b,(b / 100000));
                p[i]=b / 100000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 100000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Pa --> %.6f bar",arquivo[i],(arquivo[i]/ 100000));
            }
            break;
        }
        case -6:{// pa >> psi
            if(test==0){
                printf("\n\t%.6f Pa --> %.6f psi",b,(b / 6895));
                p[i]=b / 6895;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 6895);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Pa --> %.6f psi",arquivo[i],(arquivo[i]/ 6895));
            }
            break;
        }
        case -14:{// pa >> torr
            if(test==0){
                printf("\n\t%.6f Pa --> %.6f Torr",b,(b / 133));
                p[i]=b / 133;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 133);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Pa --> %.6f Torr",arquivo[i],(arquivo[i] / 133));
            }
            break;
        }
        case 2:{//bar >> pa
            if(test==0){
                printf("\n\t%.6f bar --> %.6f Pa",b,(b * 100000));
                p[i]=b * 100000;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 100000);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f bar --> %.6f Pa",arquivo[i],(arquivo[i]* 100000));
            }
            break;
        }
        case -4:{// bar >> psi
            if(test==0){
                printf("\n\t%.6f bar --> %.6f psi",b,(b * 14.504));
                p[i]=b * 14.504;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 14.504);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f bar --> %.6f psi",arquivo[i],(arquivo[i]* 14.504));
            }
                break;
        }
        case -12:{// bar >> torr
            if(test==0){
                printf("\n\t%.6f bar --> %.6f Torr",b,(b * 750));
                p[i]=b * 750;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 750);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f bar --> %.6f Torr",arquivo[i],(arquivo[i]* 750));
            }
            break;
        }
        case 6:{// psi >> pa
            if(test==0){
                printf("\n\t%.6f psi --> %.6f Pa",b,(b * 6895));
                p[i]=b * 6895;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 6895);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f psi --> %.6f Pa",arquivo[i],(arquivo[i]* 6895));
            }
            break;
        }
        case 4:{// psi >> bar
            if(test==0){
                printf("\n\t%.6f psi --> %.6f bar",b,(b / 14.504));
                p[i]=b / 14.504;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 14.504);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f psi --> %.6f bar",arquivo[i],(arquivo[i] / 14.504));
            }
            break;
        }
        case -8:{//psi >> torr
            if(test==0){
                printf("\n\t%.6f psi --> %.6f Torr",b,(b * 51.715));
                p[i]=b * 51.715;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 51.715);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f psi --> %.6f Torr",arquivo[i],(arquivo[i]* 51.715));
            }
            break;
        }
        case 14:{// torr >> pa
            if(test==0){
                printf("\n\t%.6f Torr --> %.6f Pa",b,(b * 133));
                p[i]=b * 133;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 133);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Torr --> %.6f Pa",arquivo[i],(arquivo[i]* 133));
            }
            break;
        }
        case 12:{// torr >> bar
            if(test==0){
                printf("\n\t%.6f Torr --> %.6f bar",b,(b / 750));
                p[i]=b / 750;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 750);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Torr --> %.6f bar",arquivo[i],(arquivo[i]/ 750));
            }
            break;
        }
        case 8:{// torr >> psi
            if(test==0){
                printf("\n\t%.6f Torr --> %.6f psi",b,(b / 51.715));
                p[i]=b / 51.715;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 51.715);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Torr --> %.6f psi",arquivo[i],(arquivo[i]/ 51.715));
            }
            break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menupressao(0);
    }
}
void menupressao(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO PARA PRESSÃO:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Pascal\t\t\t\t[Pa]");
            printf("\n\t4) Bar\t\t\t\t\t[bar]");
            printf("\n\t8) Libra força por polegada quadrada \t[psi]");
            printf("\n\t16) Torr\t\t\t\t[Torr]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertpressao(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertpressao(j,1,0);
    }
}

void converttemperatura(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//C >> F
            if(test==0){
                printf("\n\t%.6f ºC --> %.6f ºF",b,((b * 1.8)+32));
                p[i]= (b * 1.8)+32;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b * 1.8)+32);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ºC --> %.6f ºF",arquivo[i],(arquivo[i] * 1.8)+32);
            }
            break;
        }
        case -6:{// C >> K
            if(test==0){
                printf("\n\t%.6f ºC --> %.6f K",b, b + 273.15);
                p[i]= b + 273.15;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b + 273.15);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ºC --> %.6f K",arquivo[i],(arquivo[i] + 273.15));
            }
            break;
        }
        case -14:{// C >> Rankine
            if(test==0){
                printf("\n\t%.6f ºC --> %.6f Ra",b, (b * 1.8) + 32 + 459.67);
                p[i]= (b * 1.8) + 32 + 459.67;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b * 1.8) + 32 + 459.67);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ºC --> %.6f Ra",arquivo[i],(arquivo[i] * 1.8) + 32 + 459.67);
            }
            break;
        }
        case 2:{//F >> C
            if(test==0){
                printf("\n\t%.6f ºF --> %.6f ºC",b, (b - 32) / 1.8);
                p[i]= (b - 32) / 1.8;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b - 32) / 1.8);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ºF --> %.6f ºC",arquivo[i],((arquivo[i]- 32) / 1.8));
            }
            break;
        }
        case -4:{// F >> K
            if(test==0){
                printf("\n\t%.6f ºF --> %.6f K",b, (b + 459.67) / 1.8);
                p[i]= (b + 459.67) / 1.8;
                i++;
                do{
                    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b + 459.67) / 1.8);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ºF --> %.6f K",arquivo[i],(arquivo[i] + 459.67) / 1.8);
            }
            break;
        }
        case -12:{// F >> Rankine
            if(test==0){
                printf("\n\t%.6f ºF --> %.6f Ra",b,b + 459.67);
                p[i]= b + 459.67;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b + 459.67);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ºF --> %.6f Ra",arquivo[i],(arquivo[i] + 459.67));
            }
            break;
        }
        case 6:{// K >> C
            if(test==0){
                printf("\n\t%.6f K --> %.6f ºC",b,(b - 273.15));
                p[i]= b - 273.15;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b - 273.15);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f K --> %.6f ºC",arquivo[i],(arquivo[i] - 273.15));
            }
            break;
        }

        case 4:{// k >> F
            if(test==0){
                printf("\n\t%.6f K --> %.6f ºF",b, (b * 1.8) - 459.67);
                p[i]= (b * 1.8) - 459.67;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b * 1.8) - 459.67);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f K --> %.6f ºF",arquivo[i],(arquivo[i] * 1.8) - 459.67);
            }
            break;
        }

        case -8:{// K >> Rankine
            if(test==0){
                printf("\n\t%.6f K --> %.6f Ra",b, b * 1.8);
                p[i]= b * 1.8;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b * 1.8));
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f K --> %.6f Ra",arquivo[i],(arquivo[i] * 1.8));
            }
            break;
        }

        case 14:{// Rankine >> C
            if(test==0){
                printf("\n\t%.6f Ra --> %.6f ºC",b, (b - 32 - 459.67) / 1.8);
                p[i]= (b - 32 - 459.67) / 1.8;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao((b - 32 - 459.67) / 1.8);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Ra --> %.6f ºC",arquivo[i],(arquivo[i]*(b - 32 - 459.67) / 1.8));
            }
            break;
        }

        case 12:{ // Rankine >> F
            if(test==0){
                printf("\n\t%.6f Ra --> %.6f ºF",b, b - 459.67);
                p[i]= b - 459.67;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b - 459.67);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Ra --> %.6f ºF",arquivo[i],(arquivo[i]*(b - 459.67)));
            }
            break;
        }

        case 8:{ // Rankine >> K
            if(test==0){
                printf("\n\t%.6f Ra --> %.6f K",b, b / 1.8);
                p[i]= b / 1.8;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1.8);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPERATURA POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f Ra --> %.6f K",arquivo[i],(arquivo[i] / 1.8));
            }
            break;
        }

        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menutemperatura(0);
    }
}
void menutemperatura(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO DE TEMPERATURA:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Celsius\t[ºC]");
            printf("\n\t4) Fahrenheit\t[ºF]");
            printf("\n\t8) Kelvin \t[K]");
            printf("\n\t16) Rankine\t[Ra]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            converttemperatura(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        converttemperatura(j,1,0);
    }
}

void convertvelocidade(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//Metro por segundo>>ft por segundo
            if(test==0){
                printf("\n\t%.6f m/s --> %.6f ft/s",b,(b * 3.28084));
                p[i]=b*3.28084;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 3.28084);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m/s --> %.6f ft/s",arquivo[i],(arquivo[i]* 3.28084));
            }
            break;
        }
        case -6:{//Metro por segundo>>Milhas por hora
            if(test==0){
                printf("\n\t%.6f m/s --> %.6f mph",b,(b *2.23694));
                p[i]=b *2.23694;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b*2.23694);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m/s --> %.6f mph",arquivo[i],(arquivo[i]*2.23694));
            }
            break;
        }
        case -14:{//Metro por segundo>>Nó
            if(test==0){
                printf("\n\t%.6f m/s --> %.6f nós",b,(b * 1.943846));
                p[i]=b * 1.943846;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1.943846);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m/s --> %.6f nós",arquivo[i],(arquivo[i]* 1.943846));
            }
            break;
        }
        case 2:{//ft por segundo>>metro por segundo
            if(test==0){
                printf("\n\t%.6f ft/s --> %.6f m/s",b,(b / 3.28084));
                p[i]=b / 3.28084;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 3.28084);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ft/s --> %.6f m/s",arquivo[i],(arquivo[i]/ 3.28084));
            }
            break;
        }
        case -4:{//ft por segundo>>milhas por hora
            if(test==0){
                printf("\n\t%.6f ft/s --> %.6f mph",b,(b / 1.467));
                p[i]=b / 1.467;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1.467);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ft/s --> %.6f mph",arquivo[i],(arquivo[i]/ 1.467));
            }
            break;
        }
        case -12:{//ft por segundo>>nós
            if(test==0){
                printf("\n\t%.6f ft/s --> %.6f nós",b,(b / 1.688));
                p[i]=b / 1.688;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                salvarConversao(b/ 1.688);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ft/s --> %.6f nós",arquivo[i],(arquivo[i]/ 1.688));
            }
            break;
        }
        case 6:{//milhas por hora>>metro por segundo
        if(test==0){
                printf("\n\t%.6f mph --> %.6f m/s",b,(b / 2.237));
                p[i]=b / 2.237;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                salvarConversao(b / 2.237);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f mph --> %.6f m/s",arquivo[i],(arquivo[i]/ 2.237));
            }
            break;
        }
        case 4:{//milhas por hora>>ft por segundo
            if(test==0){
                printf("\n\t%.6f mph --> %.6f ft/s",b,(b * 1.467));
                p[i]=b * 1.467;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1.467);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f mph --> %.6f ft/s",arquivo[i],(arquivo[i]* 1.467));
            }
            break;
        }
        case -8:{//milhas por hora>>Nós
            if(test==0){
                printf("\n\t%.6f mph --> %.6f nós",b,(b / 1.151));
                p[i]=b / 1.151;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b/ 1.151);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f mph --> %.6f nós",arquivo[i],(arquivo[i]/ 1.151));
            }
            break;
        }
        case 14:{//Nós>>metro por segundo
            if(test==0){
                printf("\n\t%.6f nós --> %.6f m/s",b,(b / 1.944));
                p[i]=b*32.38;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 1.944);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f nós --> %.6f m/s",arquivo[i],(arquivo[i]/ 1.944));
            }
            break;
        }
        case 12:{//Nós>>ft por segundo
            if(test==0){
                printf("\n\t%.6f nós --> %.6f ft/s",b,(b * 1.688));
                p[i]=b * 1.688;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 1.688);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f nós --> %.6f ft/s",arquivo[i],(arquivo[i]*1.688));
            }
            break;
        }
        case 8:{//Nós>>Milhas por hora
            if(test==0){
                printf("\n\t%.6f nós --> %.6f mph",b,(b * 1.151));
                p[i]=(b * 1.151);
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);

                if(aux==1){
                    salvarConversao(b * 1.151);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE VELOCIDADE POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f nós --> %.6f mph",arquivo[i],(arquivo[i]* 1.151));
            }
            break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menuvelocidade(0);
    }
}
void menuvelocidade(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO DE VELOCIDADE:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Metros por segundo\t[m/s]");
            printf("\n\t4) Pés por segundo\t[ft/s]");
            printf("\n\t8) Milhas por hora \t[mph]");
            printf("\n\t16) Nós\t");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertvelocidade(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertvelocidade(j,1,0);
    }
}

void convertvolume(int a,float b,int i){
    int aux=0;
    switch(a){
        case -2:{//g >> m^3
            if(test==0){
                printf("\n\t%.6f gal --> %.6f m³",b,(b / 264));
                p[i]=b / 264;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 264);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f gal --> %.6f m³",arquivo[i],(arquivo[i]/ 264));
            }
            break;
        }
        case -6:{//g>>ft^3
            if(test==0){
                printf("\n\t%.6f gal --> %.6f ft³",b,(b * 231));
                p[i]=b * 231;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 231);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f gal --> %.6f ft³",arquivo[i],(arquivo[i]* 231));
            }
            break;
        }
        case 2:{//m^3>> g
            if(test==0){
                printf("\n\t%.6f m³ --> %.6f gal",b,(b * 264.172));
                p[i]=b * 264.172;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 264.172);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m³ --> %.6f gal",arquivo[i],(arquivo[i]* 264.172));
            }
            break;
        }
        case -4:{//m^3>>ft^3
            if(test==0){
                printf("\n\t%.6f m³ --> %.6f ft³",b,(b * 61023.7));
                p[i]=b * 61023.7;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b * 61023.7);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f m³ --> %.6f ft³",arquivo[i],(arquivo[i]* 61023.7));
            }
            break;
        }
        case 6:{//ft^3>>g
            if(test==0){
                printf("\n\t%.6f ft³ --> %.6f gal",b,(b / 231));
                p[i]=b / 231;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 231);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ft³ --> %.6f gal³",arquivo[i],(arquivo[i]/ 231));
            }
            break;
        }
        case 4:{//ft^3>>m^3
            if(test==0){
                printf("\n\t%.6f ft³ --> %.6f m³",b,(b / 61023.7));
                p[i]=b / 61023.7;
                i++;
                do{
              	    printf("\n\n\tDeseja salvar?");
                    printf("\n\t1) Sim");
                    printf("\n\t2) Não");
                    printf("\n\tOpção: ");
                    scanf("%d",&aux);
                    fflush(stdin);
                }while (aux>2 || aux<1);
                if(aux==1){
                    salvarConversao(b / 61023.7);
                }
            }
            else{
                printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
                printf("\n\nCONVERSÃO DE TEMPO POR ARQUIVO:\n");
                for(i=3;i<linhas;i++)
                    printf("\n\t%.6f ft³ --> %.6f m³",arquivo[i],(arquivo[i]/ 61023.7));
            }
            break;
        }
        default:
            printf("\n\tCONVERSÃO NÃO RECONHECIDA");
            Sleep(4000);
            system("cls");
            menuvolume(0);
    }
}
void menuvolume(int j){
    int a,b,d=1,e=0,i=0;
    float c;
    if(test==0){
        while(d!=0){
            d=0;
            printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
            printf("\n\nCONVERSÃO PADRÃO PARA VOLUME:");
            printf("\n\n\tEscolha unidades desejadas: \n");
            printf("\n\t2) Galões americanos\t[gal]");
            printf("\n\t4) Metros cúbicos\t[m³]");
            printf("\n\t8) Pés cúbicos\t\t[ft³]");
            printf("\n\n\tUnidade de origem: ");
            scanf("%d",&a);
            fflush(stdin);
            printf("\tUnidade de destino: ");
            scanf("%d",&b);
            fflush(stdin);
            printf("\tVALOR: ");
            scanf("%f",&c);
            fflush(stdin);
            convertvolume(a-b,c,i);
            i++;
            printf("\n\tO que você deseja agora?");
            printf("\n\t0) SAIR");
            printf("\n\t1) CONTINUAR");
            printf("\n\tOpção: ");
            scanf("%d",&d);
            fflush(stdin);
            p=(int*)realloc(p,(TAM++)*sizeof(int));
            system("cls");
        }
    }
    else{
        convertvolume(j,1,0);
    }
}

float recursao(float x,float y){
    if(x>=0)
        if(x==0)
            return y;
        else
            return recursao(--x,y*10);
    if(x<=0)
        if(x==0)
            return y;
        else
            return recursao(++x,y/10);
    }
void multiplo(void){
    float a,b;
    int d=0, i=0, aux=0;
        system("cls");
        printf("\a\n================================================= CONVERSÃO DE UNIDADES ================================================");
        printf("\n\nCONVERSÃO PADRÃO PARA MÚLTIPLOS:");
        printf("\n\n\tEscolha unidades desejadas: \n");
        printf("\n\t12) Tera\t");
        printf("\n\t9) Giga\t");
	    printf("\n\t6) Mega\t");
        printf("\n\t3) Quilo\t");
        printf("\n\t2) Hecto\t");
        printf("\n\t4) Deca\t");
	    printf("\n\t-1) Doci\t");
        printf("\n\t-2) Centi\t");
        printf("\n\t-3) Mili\t");
        printf("\n\t-6) Micro\t");
	    printf("\n\t-9) Nano\t");
	    printf("\n\n\tVALOR: ");
        scanf("%f",&a);
        fflush(stdin);
        printf("\tMúltiplo: ");
        scanf("%f",&b);
        fflush(stdin);
    if(b>0){
        printf("\n\t%.10f\n",recursao(b,a));
        p[i]= recursao(b,a);
        i++;
        do{
            printf("\n\tDeseja salvar?");
            printf("\n\t1) Sim");
            printf("\n\t2) Não");
            printf("\n\tOpção: ");
            scanf("%d",&aux);
            fflush(stdin);
        }while (aux>2 || aux<1);
        if(aux==1){
            salvarConversao(recursao(b,a));
        }
        p=(int*)realloc(p,(TAM++)*sizeof(int));
    }
    else{
        printf("\n\t%.10f\n",recursao(b,a));
        p[i]= recursao(b,a);
        i++;
        do{
            printf("\n\tDeseja salvar?");
            printf("\n\t1) Sim");
            printf("\n\t2) Não");
            printf("\n\tOpção: ");
            scanf("%d",&aux);
            fflush(stdin);
        }while (aux>2 || aux<1);
        if(aux==1){
            salvarConversao(recursao(b,a));
        }
        p=(int*)realloc(p,(TAM++)*sizeof(int));
    }

    printf("\n\tO que você deseja agora?");
    printf("\n\t0) SAIR");
    printf("\n\t1) CONTINUAR");
    printf("\n\tOpção: ");
    scanf("%d",&d);
    fflush(stdin);

    if(d==1){
        multiplo();
    }
}

void salvarConversao(float resp){
    char ARQUIVO[] = "CAMINHO DO ARQUIVO";
    char MODO[] = "a";
    FILE *fd = NULL;
    fd = fopen(ARQUIVO, MODO);
    if(fd == NULL ){
        printf("\nErro na abertura do arquivo.");
        exit(1);
    }
    fprintf(fd, "\n%f", resp );
	fclose(fd);
}
