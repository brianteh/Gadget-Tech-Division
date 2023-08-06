
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Special pins
#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19


#include <Tone.h>
#include <CapacitiveSensor.h>
//#include <ArduinoSTL.h>




const int num_speaker = 3;
const int num_key = 5;



Tone* tone_arr[num_speaker];
int playing_arr[num_speaker];

int pin_arr[num_speaker]={2,3,4};

bool current_arr[num_key];
//int val_arr[num_key];


int send_pin_arr[num_key]={A1,A2,A3,A4,A5};
int recv_pin_arr[num_key]={12,11,10,9,8};

int thres=400;


CapacitiveSensor* cap_arr[num_key];
int note_arr[num_key] = {NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4};




void setup() {
  Serial.begin(9600);
 
  for(int i=0;i<num_speaker;i++){
    tone_arr[i] = new Tone();
    tone_arr[i]->begin(pin_arr[i]);
  }
  
  for(int i=0;i<num_key;i++){
    cap_arr[i] = new CapacitiveSensor(send_pin_arr[i],recv_pin_arr[i]);
  }
  
  
}



void loop() {
  
  for(int i=0;i<num_key;i++ ){
    long val = cap_arr[i]->capacitiveSensor(30);
    Serial.print("val_");
    Serial.print(i);
    Serial.print(":");
    Serial.println(val);
    if(val>thres){
      int occupied=0;
      for(int k=0;k<num_key;k++){
        if(current_arr[k]){
          occupied+=1;
        }
      }
      if(occupied<num_speaker){
        current_arr[i]=true;
      }
    }else{
      for(int j=0;j<num_speaker;j++){
        if(playing_arr[j]==i){
          if(tone_arr[j]->isPlaying()){
            tone_arr[j]->stop();
            //delay(10);
          }
        }
      }
      current_arr[i]=false;
    }
   
  }
  
  int count=0;
  for(int i=0;i<num_key;i++){
    if(current_arr[i]){
      if(!(tone_arr[count]->isPlaying())){
        tone_arr[count]->play(note_arr[i]);
        playing_arr[count]=i;
        count+=1;
      }
    }
  }

  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
}
