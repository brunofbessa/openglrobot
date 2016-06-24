/*
  Autor: Bruno Fernandes Bessa de Oliveira
 */

//Libraries needed
#include <GL/glut.h>
#include <stdlib.h>
#include "def.h"
#include <math.h>

//Initializing rendering parameters
void init(void) 
{
   //Colours 
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

//Creating objects
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   zord();
   obstaculo();
   glutSwapBuffers();
   glFlush();     
}

//Projecions
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

//Callback for programed moves
void timer(){
  switch(d){
    //"dance"
    case 0:   
      //lengs and arms have a pi/2 fase
      pdirx = 40*cos(w0*t) - 20;
      pbdir = 60*sin(w0*t) + 60;
      pesqx = 40*sin(w0*t) - 20;
      pbesq = 60*sin(w0*t) + 60;
      bdirx = 15*sin(w0*t);
      pdirz = 3*cos(w0*t) - 3;
      pesqz = 3*sin(w0*t) + 3;
      //Touching ball
      yp = 1.2*cos(pdirx) + cos(pbdir);  //Robot's foot
      zp = 1.2*sin(pdirx) + sin(pbdir);
      if ((zp > 2.1) && (pdirx < 0.0)){
        mov = 1;
      }  
      //Kicking the ball
      if (mov == 1){
        xo = xo - vx*t;
        yo = yo + vy*t;
        zo = zo + vz*t;
      }        
      besqx = 25*sin(w0*t);
      aesq = 25*cos(w0*t) - 25;
      bdirx = 25*cos(w0*t);
      adir = 25*cos(w0*t) - 25;
      bdirz = 5*cos(w0*t) - 5;
      besqz = 5*cos(w0*t) + 5;
      troncoy = 15*sin(w0*t);
      troncox = 5*sin(w0*t);
      cinty = 10*sin(w0*t);
      //Time passes by
      t += 1; 
      glutPostRedisplay();
      glutTimerFunc(33,timer, 1);
      break;
    //do nothing
    case 1:
       //Remove ball  
       xo = 100;
       yo = 100;
       zo = 100;
       glutPostRedisplay();
       break;
    //end
    case 2:
      exit(0);
          
  }  
}

//Dictionary for the moves - sorry it's not in English
/*
Dicionario de teclas:
           
           l - rotaciona em y
           L - rotaciona em x
           ; - rotaciona em z
           
           
           a - frexa antebraco esquerdo
           A - abre antebraco esquerdo
           s - frexa antebraco direito
           S - abre antebraco direito
           b - ergue braco esquerdo em x para frente
           B - ergue braco esquerdo em x para tras
           n - ergue braco direito em x para frente
           N - ergue braco direito em x para tras
           g - gira braco esquerdo em z para fora
           G - gira braco esquerdo em z para dentro
           h - gira braco direito em z para fora
           H - gira braco direito em z para dentro
           c - gira cabeca para a direita
           C - gira cabeca para a esquerda
           k - dobra joelho esquerdo
           K - dobra joelho direito
           p - ergue perna esquerda em x para frente
           P - ergue perna esquerda em x para tras
           o - ergue perna direita em x para frente
           O - ergue perna direita em x para tras
           i - ergue perna esquerda para fora
           I - ergue perna esquerda para dentro
           u - ergue perna direita para fora
           U - ergue perna direia para dentro
           t - gira o tronco em x para frente
           T - gira o tronco em x para tras
           r - gira o tronco em y para a esquerda
           R - gira o tronco em y para a direita
           q - encerra o aplicativo
           d - modificar o modo de apresentacao: danca/operacional
           "espaco" - no modo opracional, recoloca Zord na posicao inicial
*/
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'l':  
         rotlat1 = (rotlat1 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'L':
         rotlat2 = (rotlat2 + 5) % 360;
         glutPostRedisplay();
         break;
      case ';':
         rotlat3 = (rotlat3 + 5) % 360;
         glutPostRedisplay();
         break;   
      case 'c':
         if ((cabeca <= 80) && (cabeca >= -90)){  
           cabeca = (cabeca + 5) % 360;
         }  
         glutPostRedisplay();
         break;
      case 'C':
         if ((cabeca <= 90) && (cabeca >= -80)){  
           cabeca = (cabeca - 5) % 360;
         }  
         glutPostRedisplay();
         break;
   
      case 't':
         if ((troncox <= 70) && (troncox >= -30)){  
           troncox = (troncox + 5) % 360;
           glutPostRedisplay();
           }
         break;
      case 'T':
         if ((troncox <= 75) && (troncox >= -25)){
           troncox = (troncox - 5) % 360;
           glutPostRedisplay();
         }
         break; 
      case 'r':
         if ((troncoy <= 30) && (troncoy >= -33)){  
           troncoy = (troncoy + 5) % 360;
           glutPostRedisplay();
           }
         break;
      case 'R':
         if ((troncoy <= 35) && (troncoy >= -27)){  
           troncoy = (troncoy - 5) % 360;
           glutPostRedisplay();
           }
         break;            
      case 'b':
         if (besqx >= -170){
           besqx = (besqx - 5) % 360;
         }
         glutPostRedisplay();
         break;
      case 'B':
         if ((besqx <= 35) && (besqx >= -175)){
           besqx = (besqx + 5) % 360;
           glutPostRedisplay();  
         }            
         break;
      case 'n':
         if (bdirx >= -170){
           bdirx = (bdirx - 5) % 360;
           }  
         glutPostRedisplay();
         break;
      case 'N':
         if ((bdirx <= 35) && (bdirx >= -175)){
           bdirx = (bdirx + 5) % 360;
           glutPostRedisplay();  
         }            
         break;
      case 'g':   
         if (besqz  <= 120){
           besqz = (besqz + 5) % 360;
         }
         glutPostRedisplay();
         break;
      case 'G':   
         if (besqz  >= 3){
           besqz = (besqz - 5) % 360;
         }
         glutPostRedisplay();
         break;
      case 'h':
         if (bdirz  >=- 120){
           bdirz = (bdirz - 5) % 360;
         }
         glutPostRedisplay();
         break;                   
      case 'H':
         if (bdirz  < -3){
           bdirz = (bdirz + 5) % 360;
         }
         glutPostRedisplay();
         break;
      case 'a':
         if (aesq >= -130){
           aesq = (aesq - 5) % 360;
         }  
         glutPostRedisplay();
         break;  
      case 'A':
         if (aesq < 0){
           aesq = (aesq + 5) % 360;
         }  
         glutPostRedisplay();
         break;    
      case 's':
         if (adir >= -130){  
           adir = (adir - 5) % 360;
         }  
         glutPostRedisplay();
         break;   
      case 'S':
         if (adir < 0){  
           adir = (adir + 5) % 360;
         }  
         glutPostRedisplay();
         break; 
      case 'p':
         if (pesqx >= -100){  
           pesqx = (pesqx - 5) % 360;
         }  
         glutPostRedisplay();
         break;
      case 'P':
         if (pesqx < 0){  
           pesqx = (pesqx + 5) % 360;
         }  
         glutPostRedisplay();
         break;
      case 'o':
         if (pdirx >= -100){
           pdirx = (pdirx - 5) % 360;
           }
         glutPostRedisplay();
         break;
      case 'O':
         if (pdirx < 0){
           pdirx = (pdirx + 5) % 360;
           }
         glutPostRedisplay();
         break;
      case 'i':
         if (pesqz <= 70){  
           pesqz = (pesqz + 5) % 360;
         }  
         glutPostRedisplay();
         break;
      case 'I':
         if (pesqz > 0){  
           pesqz = (pesqz - 5) % 360;
         }  
         glutPostRedisplay();
         break;
      case 'u':
         if (pdirz >= -70){
           pdirz = (pdirz - 5) % 360;
           }
         glutPostRedisplay();
         break;
      case 'U':
         if (pdirz < 0){
           pdirz = (pdirz + 5) % 360;
           }
         glutPostRedisplay();
         break;
      case 'k':
         if (pbesq <= 130){
           pbesq = (pbesq + 5) % 360;
           }
         glutPostRedisplay();
         break;   
      case 'K':
         if (pbesq > 0){
           pbesq = (pbesq - 5) % 360;
           }
         glutPostRedisplay();
         break;   
      case 'j':
         if (pbdir <= 130){  
           pbdir = (pbdir + 5) % 360;
           }
         glutPostRedisplay();
         break;   
      case 'J':
         if (pbdir > 0){  
           pbdir = (pbdir - 5) % 360;
           }
         glutPostRedisplay();
         break;
      case 'q':
         exit(0);
         break;
      case 'd':
         timer();
         d = d + 1;
         angulos();
         glutPostRedisplay();
         break;     
      case ' ':
         d = 0;  
         angulos();
         glutPostRedisplay();
         break;     
         
      default:
         break;
   }
}

//Main function
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 500); 
   glutCreateWindow("Zord!");
   init();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(33, timer, 1);
   glutMainLoop();
   return 0;
}

