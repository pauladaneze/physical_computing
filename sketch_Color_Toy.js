var serial; // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem1411';  // fill in your serial port name here
var inData;
var button1;
var button2;
var button3;

function setup() {
 createCanvas(2000, 1024);
 
 serial = new p5.SerialPort();    // make a new instance of the serialport library
 serial.on('list', printList);    // set a callback function for the serialport list event
 serial.on('data', serialEvent);    // callback for when new data arrives
 
 // change the data rate to whatever you wish
 var options = { baudrate: 9600};
 serial.open(portName, options);

}


function draw() {

  //console.log(button1);
  if (button1 == 0) {
    background('red');
  }

  if (button2 == 0) {
    background('green');
  }

  if (button3 == 0) {
    background('blue')

  }
  if (button1 == 0 && button2 == 0) {
    background('yellow');
  }

  if (button1 == 0 && button3 == 0) {
    background('magenta');
  }

  if (button2 == 0 && button3 == 0) {
    background('cyan');
  }

  if (button1 == 0 && button2 == 0 && button3 == 0) {
    background(255, 255, 255);
  }



}

  //ellipse(width/2, height/2, inData, 100);
  //ellipse(locH, locV, 50, 50); // draw the circle
  //print out the sensor value
 // text("sensor value: " + inData, 30, 30);

function serialEvent() {
  // retreive value from serial port
  inData = serial.readStringUntil('\r\n');
  if (inData.length > 0) {
    var sensor = split(inData, ',');
    
    //console.log(sensor[0]);

    button1 = sensor[0];
    console.log(button1);
    button2 = sensor[1]; 
    button3 = sensor[2];

    //if (sensor.length > 1) {
     // console.log(sensor[0]);
     // background(0);
     // fill(255);
    //console.log(sensor[0]);
    //console.log(sensor[1]);

    //if (sensor[0] == 0);
    //background('red');


    
    //console.log(sensor[1]);
   

    //circleColor = 255 - (sensor[0] * 255);
  }
  }


// print list of ports for debugging
function printList(portList) {
  // portList is an array of serial port names
  for (var i = 0; i < portList.length; i++) {
    // Display the list the console:
  print(i + " " + portList[i]);
   }
}
