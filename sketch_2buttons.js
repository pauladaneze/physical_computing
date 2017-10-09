var serial; // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem1411';  // fill in your serial port name here
var inData;
var button1;
var button2;

function setup() {
 createCanvas(400, 300);
 
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
  if ((button1 == 0 && button2 == 0)) {
    background('yellow');
  }


}



function serialEvent() {
  // retreive value from serial port
  inData = serial.readStringUntil('\r\n');
  if (inData.length > 0) {
    var sensor = split(inData, ',');
    
    //console.log(sensor[0]);

    button1 = sensor[0];
    console.log(button1);
    button2 = sensor[1]; 

    
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
