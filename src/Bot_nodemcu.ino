//PID CONTROL
//********************
double r,aprev=0,v,kp=0.5,kd=0.45;
// r->radius of robot body's circumcircle
//apprev->error in orientation in previous iteration,initially set to zero
// kp,kd->PID constants
//v->robot speed
void angle(double a)//rectifying the error in orientation
{
  double t=(a*r)/v;
  double output= (kp*a+kd(a-aprev)/t);
  t=(output*r)/v;
  digitalWrite(in1a,HIGH);
  digitalWrite(in2a,LOW);
  digitalWrite(in1b,HIGH);
  digitalWrite(in2b,LOW);
  digitalWrite(in1c,HIGH);
  digitalWrite(in2c,LOW);
  digitalWrite(in1d,HIGH);
  digitalWrite(in2d,LOW);
  analogWrite(enableA,v);
  analogWrite(enableB,v);
  analogWrite(enableC,v);
  analogWrite(enableD,v);
  aprev=a; 
  delay((int)t);
}
void getPosition(double &x,double &y,double &xf,double &yf)
                                     //extracts robot co-ordinates via live video feed
{
  x=//robot's current x-co-ordinate
  y=//robot's current y-co-ordinate
  xf=//robot's desired x-co-ordinate
  yf=//robot's desired y-co-ordinate
}
long long splitmix64(long long  x)
{
 x+=0x9e3779b97f4a7c15; 
 x=(x^(x>>30))*0xbf58476d1ce4e5b9; 
 x=(x^(x>>27))*0x94d049bb133111eb; 
 return x^(x>>31);
}
void set_speed(double v)
{
  analogWrite(enableA,v);
  analogWrite(enableB,v);
  analogWrite(enableC,v);
  analogWrite(enableD,v);
}
void error(double c,double cf,int f)//f=1 for movement along y-axis f=0 for movement along x-axis
{
 double err=(cf-c); 
 double change_vel=err;
 v-=change_vel;//as the robot gets closer to the target,the velocity of the robot decreases
 long long FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
 FIXED_RANDOM=splitmax64(FIXED_RANDOM+kp);
 set_speed(v*FIXED_RANDOM);   
}
void setup()
{
 pinMode(in1a,OUT); pinMode(in2a,OUT); 
 pinMode(in1b,OUT); pinMode(in2b,OUT);
 pinMode(in1c,OUT); pinMode(in2c,OUT);
 pinMode(in1d,OUT); pinMode(in2d,OUT);
 pinMode(enableA,OUT); pinMode(enableB,OUT); pinMode(enableC,OUT); pinMode(enableD,OUT); 
 v=//setting initial robot speed ,over the course of the maze, speed does not exceed this value
}
void loop() 
{
 double x,y,xf,yf; // x,y->initial position of robot xf,yf->position of robot as to where it should be
 double a=(yf-y)/(xf-x);  
 angle(a);
 if(xf!=x)
 {
 error(x,xf,0); 
 }   
 else
 {
 error(y,yf,1); 
 }
 delay(2000); 
}


//**************
//receiving coordinates from laptop by NodeMCU
//**************
void loop()
{
const char* ssid     = "asati";
const char* password = "naibatana";

WiFiServer server(80);
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    String tmp ="";
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) { // if there's bytes to read from the client,
        char c = client.read();
        tmp+=c;
//        
                    // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }    
          
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println(tmp);
    Serial.println("");
  
  int jk=5;
  long rj = 0;
  while(isDigit(tmp[jk])){
   rj = (rj*10)+(((int)tmp[jk])-48); 
   jk++;
  }
  Serial.println(rj);}
  //this(rj) is the target x_coordinate received by nodemcu;
  //similarly current x_position,current y_position,target y_coordinate will be received by nodemcu and fed to PID.
}
