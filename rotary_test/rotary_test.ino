/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define CLK_1 D5
 #define DT_1 D4
 #define SW_1 D3

 #define CLK_2 D8
 #define DT_2 D9
 #define SW_2 D10
 
 int counter_1 = 0; 
 int counter_2 = 0; 

 int CLK_1_State;
 int CLK_2_State;
 int CLK_1_Last_State;
 int CLK_2_Last_State;

 int aLastButton_1;
 int aLastButton_2;

 void setup() { 
  pinMode (CLK_1, INPUT);
  pinMode (CLK_2, INPUT);

  pinMode (DT_1, INPUT);
  pinMode (DT_2, INPUT);


  pinMode (SW_1, INPUT_PULLUP);
  pinMode (SW_2, INPUT_PULLUP);
  
  Serial.begin (9600);
  // Reads the initial state of the outputA

  CLK_1_Last_State = digitalRead(CLK_1);
  CLK_2_Last_State = digitalRead(CLK_2);

  aLastButton_1 = digitalRead(SW_1);
  aLastButton_2 = digitalRead(SW_2);
 } 

 void loop() { 
    int button_1 = digitalRead(SW_1);
    int button_2 = digitalRead(SW_2);

    CLK_1_State = digitalRead(CLK_1);
    if (CLK_1_State != CLK_1_Last_State){     
      if (digitalRead(DT_1) != CLK_1_State) { 
        counter_1 ++;
      } else {
        counter_1 --;
      }
      Serial.print("Position1: ");
      Serial.println(counter_1);
    } 

    CLK_2_State = digitalRead(CLK_2);
    if (CLK_2_State != CLK_2_Last_State){     
      if (digitalRead(DT_2) != CLK_2_State) { 
        counter_2 ++;
      } else {
        counter_2 --;
      }
      Serial.print("Position2: ");
      Serial.println(counter_2);
    } 

    if (button_1 != aLastButton_1) {
      counter_1 = 0;
      Serial.print("Position1: ");
      Serial.println(counter_1);
    }

    if (button_2 != aLastButton_2) {
      counter_2 = 0;
      Serial.print("Position2: ");
      Serial.println(counter_2);
    }

    CLK_1_Last_State = CLK_1_State;
    CLK_2_Last_State = CLK_2_State;
    aLastButton_1 = button_1;
    aLastButton_2 = button_2;
 }