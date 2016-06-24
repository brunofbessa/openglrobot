//This file contains the definitions for the functions used in main program.

//Variables
static int cabeca = 0; 
static int besqx = 0;
static int besqz = 0;
static int bdirx = 0;
static int bdirz = 0;
static int aesq = 0;
static int adir = 0;
static int pesqx = 0;
static int pesqz = 0;
static int pdirx = 0;
static int pdirz = 0;
static int pbesq = 0;
static int pbdir = 0;
static int troncox = 0;
static int troncoy = 0;
static int troncoz = 0;
static int cinty = 0;
double zp = 0;
double yp = 0;

//Rotate scenario
static int rotlat1 = 0;
static int rotlat2 = 0;
static int rotlat3 = 0;

//Decision about moves
static int d = 0;

//Variables for the move
double w0 = 0.1; //Angular frequence
int t = 0; //"time"

//Positioning obstacles
double xo = -0.4;
double yo = -1.5;
double zo = 1.8;

//Ball's velocity
double vx = 0.0005;
double vy = 0.001;
double vz = 0.002;
//Decision about moves of the ball
int mov = 0;

//Set default angles
void angulos(){
  cabeca = 0; 
  besqx = 0;
  besqz = 0;
  bdirx = 0;
  bdirz = 0;
  aesq = 0;
  adir = 0;
  pesqx = 0;
  pesqz = 0;
  pdirx = 0;
  pdirz = 0;
  pbesq = 0;
  pbdir = 0;
  troncox = 0;
  troncoy = 0;
  troncoz = 0;
  cinty = 0;
  rotlat1 = 0;
  rotlat2 = 0;
  rotlat3 = 0;
}

//Definition of the parts of the body using OpenGL directives
void zord(){
   //Bofy
   glPushMatrix();
   //Rotations about the cannonical base
   glTranslatef (0.0, 2.3, 0.0);
   glRotatef((GLfloat) rotlat1, 0.0, 0.1, 0.0);
   glRotatef((GLfloat) rotlat2, 0.1, 0.0, 0.0);
   glRotatef((GLfloat) rotlat3, 0.0, 0.0, 0.1);
      
     //Belly
     glPushMatrix();
       glTranslatef (0.0, -1.7, 0.0);
       glRotatef ((GLfloat) troncox, 0.1, 0.0, 0.0);
       glRotatef ((GLfloat) troncoy, 0.0, 0.1, 0.0);
       glRotatef ((GLfloat) troncoz, 0.0, 0.0, 0.1);
       glTranslatef (0.0, 0.4, 0.0);
       glPushMatrix();
         glScalef (0.65, 0.8, 0.45);
         glutWireCube (1.0);  
       glPopMatrix();
     //Chest
       glTranslatef (0.0, 0.7, 0.0);
       glPushMatrix();
         glScalef (0.8, 0.55, 0.55);
         glutWireCube (1.0);
       glPopMatrix();    
 
     //Head
       glPushMatrix(); 
         glTranslatef (0.0, 0.9, 0.0);
         glRotatef ((GLfloat) cabeca, 0.0, 0.1, 0.0);
         glScalef (0.3, 0.4, 0.3);
         glutWireSphere(1,12,12);
       glPopMatrix();
     
     //Neck
       glPushMatrix();    
         glTranslatef(0.0, 0.4, 0.0);
         glRotatef((GLfloat) cabeca, 0.0, 0.2, 0.0);
         glScalef(0.15, 0.2, 0.15);
         glutWireCube(1);
       glPopMatrix();  
   
     //Arms, forearms, hands     
     //Shouldesrs
       glPushMatrix();
         glTranslatef(0.55, 0.1, 0.0);
         glScalef(1.0, 1.0, 1.0);
         glutWireSphere(0.13, 7, 7);
       glPopMatrix();  
       //
       glPushMatrix();
         glTranslatef(-0.55, 0.1, 0.0);
         glScalef(1.0, 1.0, 1.0);
       glutWireSphere(0.13, 7, 7);
     glPopMatrix();
        
     //Arms
     glPushMatrix();
       glTranslatef (0.55, 0.1, 0.0);
       glRotatef ((GLfloat) besqx, 0.1, 0.0, 0.0);
       glRotatef ((GLfloat) besqz, 0.0, 0.0, 0.1);
       glTranslatef (0.0, -0.5, 0.0); 
       glPushMatrix();
         glScalef (0.2, 0.8, 0.25);
         glutWireCube (1);
       glPopMatrix();
       //
       glTranslatef (0.0, -0.4, 0.0);
       glRotatef ((GLfloat) aesq, 0.1, 0.0, 0.0);
       glTranslatef (0.0, -0.4, 0.0);
       glPushMatrix();
         glScalef (0.2, 0.75, 0.25);
         glutWireCube (1);
       glPopMatrix();
       //
       glPushMatrix();
         glTranslatef (0.0, -0.6, 0.0);
         glScalef (0.15, 0.45, 0.25);
         glutWireCube (1.0);
      glPopMatrix();
      glPopMatrix();   
     //
     glPushMatrix();
       glTranslatef (-0.55, 0.1, 0.0);
       glRotatef ((GLfloat) bdirx, 0.1, 0.0, 0.0);
       glRotatef ((GLfloat) bdirz, 0.0, 0.0, 0.1);
       glTranslatef (0.0, -0.5, 0.0); 
       glPushMatrix();
         glScalef (0.2, 0.8, 0.25);
         glutWireCube (1);
       glPopMatrix();
       //
       glTranslatef (0.0, -0.4, 0.0);
       glRotatef ((GLfloat) adir, 0.1, 0.0, 0.0);
       glTranslatef (0.0, -0.4, 0.0);
       glPushMatrix();
         glScalef (0.2, 0.75, 0.25);
         glutWireCube (1.0);
       glPopMatrix();
       //
       glTranslatef (0.0, -0.6, 0.0);
       glScalef (0.15, 0.45, 0.25);
       glutWireCube (1.0);
     glPopMatrix();
     glPopMatrix();
     
     //Belt
     glPushMatrix();
       glRotatef ((GLfloat) cinty, 0.0, 0.1, 0.0);
       glTranslatef(0.0, -1.95, 0.0);
       glScalef(0.8, 0.5, 0.5);
       glutWireCube(1) ;
     glPopMatrix();

     //Tight   
     glPushMatrix();
       glTranslatef(0.25, -2.05, 0.0);
       glRotatef((GLfloat) pesqx, 0.1, 0.0, 0.0);
       glRotatef((GLfloat) pesqz, 0.0, 0.0, 0.1);
       glTranslatef(0.0, -0.75, 0.0);
       glPushMatrix();
         glScalef(0.35, 1.2, 0.4);
         glutWireCube(1);
       glPopMatrix();  
       //Knee
       glTranslatef(0.0, -0.7, 0.0);
       glPushMatrix();
         glScalef(1.0, 1.0, 1.0);
         glutWireSphere(0.1, 7, 7);
       glPopMatrix();  

       //Leg 
       glTranslatef(0.0, 0.0, 0.0);
       glRotatef((GLfloat) pbesq, 0.1, 0.0, 0.0);
       glTranslatef(0.0, -0.5, 0.0);
       glPushMatrix();
         glScalef(0.3, 0.9, 0.35);
         glutWireCube(1);
       glPopMatrix();  

       //
       glTranslatef(0.0, -0.5, 0.0);
       glPushMatrix();
         //glScalef(1.0, 1.0, 1.0);
         glutWireSphere(0.07, 7, 7);
       glPopMatrix();  
       //glPopMatrix();
     
       //
       //Foot
       glTranslatef(0.0, -0.15, 0.1);
       glPushMatrix();
         glScalef(0.35, 0.15, 0.7);
         glutWireCube(1);
       glPopMatrix();  
     glPopMatrix();

     //Tight
     glPushMatrix();
       glTranslatef(-0.25, -2.05, 0.0);
       glRotatef((GLfloat) pdirx, 0.1, 0.0, 0.0);
       glRotatef((GLfloat) pdirz, 0.0, 0.0, 0.1);
       glTranslatef(0.0, -0.75, 0.0);
       glPushMatrix();
         glScalef(0.35, 1.2, 0.4);
         glutWireCube(1);
       glPopMatrix();  
       //Knee
       glTranslatef(0.0, -0.7, 0.0);
       glPushMatrix();
         glScalef(1.0, 1.0, 1.0);
         glutWireSphere(0.1, 7, 7);
       glPopMatrix();  

       //Leg
       glTranslatef(0.0, 0.0, 0.0);
       glRotatef((GLfloat) pbdir, 0.1, 0.0, 0.0);
       glTranslatef(0.0, -0.5, 0.0);
       glPushMatrix();
         glScalef(0.3, 0.9, 0.35);
         glutWireCube(1);
       glPopMatrix();  

       //
       glTranslatef(0.0, -0.5, 0.0);
       glPushMatrix();
         glutWireSphere(0.07, 7, 7);
       glPopMatrix();  
     
     //Foot
       glTranslatef(0.0, -0.15, 0.1);
       glPushMatrix();
         glScalef(0.35, 0.15, 0.75);
         glutWireCube(1);
       glPopMatrix();  
     glPopMatrix();

   glPopMatrix();
}

//Definig obstacle
void obstaculo(){
     glPushMatrix();

       glRotatef((GLfloat) rotlat1, 0.0, 0.1, 0.0);
       glRotatef((GLfloat) rotlat2, 0.1, 0.0, 0.0);
       glRotatef((GLfloat) rotlat3, 0.0, 0.0, 0.1);
       glTranslatef(xo, yo, zo);
       glScalef(1.0, 1.0, 1.0);
       glutWireSphere(0.2, 15, 15);
     glPopMatrix();
}
