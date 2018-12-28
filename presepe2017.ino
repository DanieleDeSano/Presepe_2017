
// PWM pins
#define G_STRIP 			3
#define B_STRIP 			5
#define R_STRIP 			6
#define SCURO 				9
#define SOLE 				10
#define LANT_ESTERNO 		11	// ex CAPANNA

// non PWM pins
#define LANT_INTERNO 		2	// ex SPOT 
#define BANC_4 				4	// ex ROSONE
#define BANC_2 				7	// ex CAMPANILE
#define CASE_A 				8	// ex CASE
#define CASE_B 				12	// ex NORCINO SUPERIORE
#define CASE_C				13	// ex NORCINO INFERIORE
 
#define STEP 10 

void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  analogWrite(G_STRIP, 0);
  analogWrite(B_STRIP, 0);
  analogWrite(R_STRIP, 0);
  analogWrite(SCURO, 0);
  analogWrite(SOLE, 0);
  analogWrite(LANT_ESTERNO, 0);
  
  digitalWrite (LANT_INTERNO, LOW);
  digitalWrite (BANC_4, LOW);
  digitalWrite (BANC_2, LOW);
  digitalWrite (CASE_A, LOW);
  digitalWrite (CASE_B, LOW);
  digitalWrite (CASE_C, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  int i ;
 
  // fase 1
  
  //digitalWrite (LANT_ESTERNO, HIGH);
  //analogWrite (LANT_ESTERNO, 255);
  analogWrite (B_STRIP, 15);
  digitalWrite (SCURO, HIGH);
 
   // --------------------- aumento lanterna esterna
  for (int i = 0 ; i < 2000 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 2000.0);
    
    
    analogWrite(LANT_ESTERNO,  max(35,v) );
    
    delay(1);
  }  
  digitalWrite (LANT_INTERNO, HIGH);

 
  delay (2000);
  delay (6000);

  // fase 2
  
  delay (2000);

  delay (4000);

  digitalWrite (LANT_INTERNO, LOW);
  
  // --------------------- riduci lanterna esterna
  for (int i = 0 ; i < 200 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 200.0);
    
    
    analogWrite(LANT_ESTERNO,  max(35,255 - v) );
    
    delay(STEP);
  }  

  delay (1000);

  // fase 3
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 800.0);
    
    
    analogWrite(B_STRIP,  max(15,v) );
    analogWrite(SCURO,  255-v );
    
    delay(STEP);
  }  

  // fase 4
  
  digitalWrite (CASE_B, HIGH);
  delay(2000);
  digitalWrite (CASE_A, HIGH);
  delay(2000);
  digitalWrite (CASE_C, HIGH);
  delay(1000);
  
  // fase 5
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 800.0);
    
    
    analogWrite(R_STRIP,  v );
    
    delay(STEP);
  }  
  
  
  // fase 6

  digitalWrite (CASE_B, LOW);
  delay (2000);
  digitalWrite (BANC_2, HIGH);
  delay (2000);
  digitalWrite (BANC_4, HIGH);

  
  // fase 7
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 800.0);
    
    
    analogWrite(G_STRIP,  v );
    
    delay(STEP);
  }  
  
  // fase 8
  
  digitalWrite (CASE_A, LOW);
  delay(1000);

  delay(3000);
  
   for (int i = 0 ; i < 600 ; i++)
  {
    float v ;
    v = 80.0 * (i / 600.0);
    
    analogWrite(SOLE,  v );
    delay(STEP);
  }  
  digitalWrite (CASE_C, LOW);
  delay(1000);
  digitalWrite (BANC_2, LOW);
  delay(1000);
  digitalWrite (BANC_4, LOW);

   for (int i = 0 ; i < 300 ; i++)
  {
    float v ;
    v = 80 + 175.0 * (i / 300.0);
    
    analogWrite(SOLE,  v );
    delay(STEP);
  }  
  
  delay(8000);

  // fase 9
  
   for (int i = 0 ; i < 400 ; i++)
  {
    float v ;
    v = 175.0 * (i / 400.0);
    
    analogWrite(SOLE,  255-v );
    delay(STEP);
  }  
  
  digitalWrite (BANC_2, HIGH);
  delay(1000);
  digitalWrite (BANC_4, HIGH);

  
   for (int i = 0 ; i < 700 ; i++)
  {
    float v ;
    float z;
    
    v = 80.0 * (i / 700.0);

    z = 230.0 * (i / 700.0);
    
    analogWrite(SOLE,  255-175-v );
    analogWrite(R_STRIP,  255-z );
    analogWrite(G_STRIP,  255-z );
    delay(STEP);
  }  
  
  digitalWrite (CASE_C, HIGH);
  
  // fase 10
  
  
  for (int i = 0 ; i < 800 ; i++)
  {
    float v;
    
    v = 25.0 * (i / 800.0);

    analogWrite(R_STRIP,  25-v );
    analogWrite(G_STRIP,  25-v );
    if (i == 400)
    {
       digitalWrite (BANC_4, HIGH);
      
    }
    delay(STEP);
  }  

  // fase 11

  delay (2000);
  digitalWrite (CASE_A, HIGH);
  delay (2000);
  delay (3000);
  digitalWrite (BANC_4, LOW);
  delay (2000);
  digitalWrite (BANC_2, LOW);
  delay (5000);
  digitalWrite (CASE_B, HIGH);
  delay (5000);
 
  // fase 12
  
     for (int i = 0 ; i < 1800 ; i++)
  {
    float v ;
    float z;
    
    v = 240.0 * (i / 1800.0);

    z = 255.0 * (i / 1800.0);
    
    analogWrite(B_STRIP,  255-v );
    analogWrite(SCURO,  z );
    
    if (i == 700)
    {
       digitalWrite (CASE_C, LOW);
    }
    if (i == 1000)
    {
       digitalWrite (CASE_A, LOW);
    }
    if (i == 1200)
    {
       digitalWrite (CASE_B, LOW);
    }
    if (i == 1500)
    {
    //   digitalWrite (BANC_2, LOW);
    }

    if (i == 1780)
    {
    //   digitalWrite (BANC_4, LOW);
    }
    
    delay(STEP);
  }  

}
