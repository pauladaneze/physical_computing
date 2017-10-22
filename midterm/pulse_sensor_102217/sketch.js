var serial; // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem1411';  // fill in your serial port name here
var inData;
var button1;
var button2;
var button3;
var img;

//
function preload() {
  img = loadImage("heart.jpg");
}

function setup() {
 createCanvas(1400, 800);
 background(0);
 text("test " , 200, 500);
 
 serial = new p5.SerialPort();    // make a new instance of the serialport library
 serial.on('list', printList);    // set a callback function for the serialport list event
 serial.on('data', serialEvent);    // callback for when new data arrives
 
 // change the data rate to whatever you wish
 var options = { baudrate: 9600};
 serial.open(portName, options);

}


function draw() {
  //console.log(button1);

  if (inData < 100) {
    background(137, 196, 244);
    image(img, 200, 300, inData * 2, inData * 2);
  //  ellipse(250, 300, inData/2, inData/2);

  }

  if (inData > 100) {
    background('red');
    image(img, 200, 300, inData * 2, inData * 2);
    //ellipse(250, 300, inData/2, inData/2);
  }

  if (inData == 0) {
    background('white');
  }

  
  textSize(30);
  text("Your Heart Beat: " , 200, 200);
  textSize(50);
  text(inData + " bpm", 200, 250);
  

}

function serialEvent() {
  // retreive value from serial port
  inData = serial.readStringUntil('\r\n');
  if (inData.length > 0) {
    var sensor = split(inData, ',');
    
    //console.log(sensor[0]);
    // console.log(button1);

    button1 = sensor[0];
    button2 = sensor[1]; 
    button3 = sensor[2];

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
