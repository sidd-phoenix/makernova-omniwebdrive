#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <ESPmDNS.h>
#else
#error "Board not found"
#endif

#include <WebSocketsServer.h>



#define LED1 12
#define LED2 10

char devpage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Developers</title>
    <style>
        :root{
            --dark:#333;
        }

        body {
            margin: 0;
            padding: 0;
            font-family: 'Press Start 2P', cursive;
            background: linear-gradient(to bottom,darkblue,blue);
        }

        .topbar {
            display: flex;
            justify-content: space-between;
            align-items: center;
            background: linear-gradient(to right, var(--dark) , blue, var(--dark));
            color: #fff;
            padding: 10px;
        }

        .logo-container {
            width: 10%;
            height: 100%;
            display: flex;
            align-items: center;
        }

        .logo {
            max-width: 100%;
            max-height: 100%;
        }

        .title-container {
            text-align: center;
        }

        .navbar {
            text-align: center;
            background-color: var(--dark);
            display: flex;
            justify-content: flex-end;
        }

        .navbar a {
            color: white;
            text-decoration: none;
            margin: 0 15px;
        }

        .content-container {
            padding: 20px;
        }

        .title-bar {
            background-color: var(--dark);
            color: white;
            text-align: center;
            padding: 20px 0;
            margin-top: 10px;
        }

        /* Mentors Container */
        .mentors-container {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            padding: 20px;
        }

        .mentor-card {
            width: 250px;
            margin: 20px;
            background-color: #f5f5f5;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
            text-align: center;
            padding: 20px;
        }

        .mentor-photo img {
            width: 120px;
            height: 120px;
            border-radius: 50%;
            margin: 0 auto 10px;
        }

        .mentor-info h2,
        .team-info h2 {
            margin: 0;
        }

        .social-links {
            margin-top: 10px;
        }

        .github-link,
        .linkedin-link {
            display: inline-block;
            padding: 5px 10px;
            margin: 5px;
            background-color: #333;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            transition: background-color 0.3s;
        }

        .github-link:hover,
        .linkedin-link:hover {
            background-color: #555;
        }


        .team-container {
            display: grid;
            grid: repeat(3, 1fr)/repeat(4, 1fr);
        }

        .team-card {
            width: 250px;
            margin: 20px;
            background-color: #f5f5f5;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
            text-align: center;
            padding: 20px;
        }


        .team-photo img {
            width: 120px;
            height: 120px;
            border-radius: 50%;
            margin: 0 auto 10px;
        }

        @media screen and (max-width: 768px) {
            /* Adjustments for smaller screens */

            div{
                border: 2px solid red;
            }
            .logo-container {
                width: 20%;
            }

            .topbar{
                font-size: 0.4rem;
            }

            .title-container {
                text-align: center;
            }

            .navbar {
                font-size: x-small;
            }

            .mentors-container,.team-container{
                display: flex;
                flex-direction: column;
            }
        }
    </style>
//    <link rel="preconnect" href="https://fonts.googleapis.com">
//    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
//    <link href="https://fonts.googleapis.com/css2?family=Press+Start+2P&display=swap" rel="stylesheet">
</head>

<body>
    <div class="topbar">
        <div class="logo-container">
            <a href="https://svnit.ac.in"><img src="svnit_logo.png" alt="Logo 1" class="logo"></a>
        </div>
        <div class="title-container">
            <h1>OMNI WEB DRIVE</h1>
        </div>
        <div class="logo-container">
            <a href="https://drishti-svnit.github.io/drishti/"><img src="drishti_logo_white.png" alt="Logo 2" class="logo"></a>
        </div>
    </div>

    <div class="navbar">
        <a href="r1.html">Controller</a>
    </div>

    <div class="content-container">
        <div class="title-bar">
            <h1>OUR MENTORS</h1>
        </div>

        <div class="mentors-container">
            <div class="mentor-card">
                <div class="mentor-photo">
                    <img src="at.jpg" alt="AT">
                </div>
                <div class="mentor-info">
                    <h2>Aditi Tapariya</h2>
                    <div class="social-links">
                        <a href="https://github.com/adititapariya" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/aditi-tapariya" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="mentor-card">
                <div class="mentor-photo">
                    <img src="hp.jpg" alt="HP">
                </div>
                <div class="mentor-info">
                    <h2>Harshal Patel</h2>
                    <div class="social-links">
                        <a href="https://github.com/HarshalPatel15" class="github-link">GitHub</a>
                        <a href="
                        https://www.linkedin.com/in/harshal-patel-3a3a52255" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="mentor-card">
                <div class="mentor-photo">
                    <img src="rs1.jpg" alt="RS">
                </div>
                <div class="mentor-info">
                    <h2>Rohit Sulatania</h2>
                    <div class="social-links">
                        <a href="#" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/rohit-sultania-919905250
                        https://github.com/Rohitsultania21" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="mentor-card">
                <div class="mentor-photo">
                    <img src="tc.jpg" alt="TC">
                </div>
                <div class="mentor-info">
                    <h2>Tarang Chaudhari</h2>
                    <div class="social-links">
                        <a href="https://github.com/Tarang2004chaudhari" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/tarang-chaudhari-3a172925b" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
        </div>

        <div class="title-bar">
            <h1>OUR TEAM</h1>
        </div>
        <div class="team-container">
            <div class="team-card">
                <div class="team-photo">
                    <img src="as.jpg" alt="AS">
                </div>
                <div class="team-info">
                    <h2>Aadil Siddiqui</h2>
                    <div class="social-links">
                        <a href="https://github.com/sidd-phoenix" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/aadil-siddiqui-phoenix" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="ag.jpg" alt="AG">
                </div>
                <div class="team-info">
                    <h2>Ambar Gupta</h2>
                    <div class="social-links">
                        <a href="https://github.com/Ambar-Gupta22" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/ambar-gupta-704a7624a" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="dd.jpg" alt="DV">
                </div>
                <div class="team-info">
                    <h2>Deshdeepak Verma</h2>
                    <div class="social-links">
                        <a href="https://github.com/deshdeepak13" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/desh-deepak-verma-79879a239" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="dg.jpg" alt="DG">
                </div>
                <div class="team-info">
                    <h2>Dhruv Gandhi</h2>
                    <div class="social-links">
                        <a href="#" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/dhruv-gandhi-8b273b255" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="ds.jpg" alt="DS">
                </div>
                <div class="team-info">
                    <h2>Dhruv Shah</h2>
                    <div class="social-links">
                        <a href="https://github.com/Dhruvshah63" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/dhruv-shah-467362289" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="km.jpg" alt="KM">
                </div>
                <div class="team-info">
                    <h2>Kashyap Mohanty</h2>
                    <div class="social-links">
                        <a href="https://github.com/Kashyap0108" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/kashyap-mohanty-9a0707272" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="nd.jpg" alt="ND">
                </div>
                <div class="team-info">
                    <h2>Neha Dhok</h2>
                    <div class="social-links">
                        <a href="https://github.com/itsnehad
                        " class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/neha-dhok-86588a258" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="or.jpg" alt="OR">
                </div>
                <div class="team-info">
                    <h2>Om Ramanuj</h2>
                    <div class="social-links">
                        <a href="https://github.com/Omramanuj" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/om-ramanuj-511501266" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="drishti_logo.png" alt="SK">
                </div>
                <div class="team-info">
                    <h2>Saiyam Kotadiya</h2>
                    <div class="social-links">
                        <a href="#" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/saiyam-kotadiya-4aa64a255" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="ss.jpg" alt="SS">
                </div>
                <div class="team-info">
                    <h2>Saksham Samarth</h2>
                    <div class="social-links">
                        <a href="https://github.com/Saksham6395" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/saksham-samarth-84b24a285" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="stp.jpg" alt="TP">
                </div>
                <div class="team-info">
                    <h2>Tanuj Peddinti</h2>
                    <div class="social-links">
                        <a href="https://github.com/SeshunadhTANUJ" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/seshunadh-tanuj-peddinti-245477289" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
            <div class="team-card">
                <div class="team-photo">
                    <img src="vr.jpg" alt="VR">
                </div>
                <div class="team-info">
                    <h2>Vaishnavi Reddy</h2>
                    <div class="social-links">
                        <a href="https://github.com/vaishnavi1728" class="github-link">GitHub</a>
                        <a href="https://www.linkedin.com/in/chanugonipalli-vaishnavi-144353261?trk=contact-info" class="linkedin-link">LinkedIn</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>

</html>

)=====";

char controlpage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Controller</title>
    <style>
        :root{
            --dark:#333;
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        html {
            height: 100%;
        }

        body {
            height: 99%;
            background: url(./bg13_1.png);
            font-family: 'Press Start 2P', cursive;
            background-size: cover;
            background-repeat: no-repeat;
            
        }
        
        .topbar {
            display: flex;
            justify-content: space-between;
            align-items: center;
            background: linear-gradient(to right, var(--dark), blue, var(--dark));
            color: #fff;
        }
        
        .logo-container {
            width: 10%;
            height: 100%;
            display: flex;
            align-items: center;
        }
        
        .logo {
            max-width: 100%;
            max-height: 100%;
        }
        
        .title-container {
            text-align: center;
        }

        .navbar {
            text-align: center;
            background-color: #333;
            display: flex;
            justify-content: flex-end;
        }

        .navbar a {
            color: white;
            text-decoration: none;
        }

        .content-container {
            padding: 20px;
            height: 78%;
        }

        #display {
            color: white;
            text-align: center;
        }

        .controller {
            display: flex;
            justify-content: space-evenly;
            position: relative;
            top: 26%;
        }

        .left{
            display: flex;
            flex-direction: column;
            justify-content: space-evenly;
            align-items: center;
        }

        .right{
            display: flex;
            flex-direction: column;
            justify-content: space-evenly;
            align-items: center;
        }

        .joystick-container {
            width: 400px;
            height: 400px;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
        }

        .joystick {
            width: 70%;
            height: 70%;
            background-color: #333;
            border-radius: 50%;
        }


        .handle {
            width: 35%;
            height: 35%;
            background-color: royalblue;
            border-radius: 50%;
            position: relative;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            cursor: pointer;
        }

        .circular-button {
            height: 100px;
            width: 100px;
            border-radius: 50%;
            background-color: white;
        }

        .circular-button:hover {
            cursor: pointer;
        }

        @media screen and (max-width: 768px) {

            div{
                border: 2px solid red;
            }
            body{
                background:white;
            }
            .topbar{
                font-size: 0.4rem;
            }

            .navbar{
                font-size: x-small;
            }

            #display{
                color: black;
            }

            .joystick-container{
                height: 300px;
                width: 300px;
            }

            .left,.right{
                flex-direction: row;
            }
            .circular-button{
                height: 50px;
                width: 50px;
                background-color: black;
            }

            .controller{
                flex-direction: column;
            }

            .joystick-container{
                align-self: center;
            }
        }
    </style>
//    <link rel="preconnect" href="https://fonts.googleapis.com">
//    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
//    <link href="https://fonts.googleapis.com/css2?family=Press+Start+2P&display=swap" rel="stylesheet">
</head>

<body>
    <div class="topbar">
        <div class="logo-container">
            <a href="https://svnit.ac.in"><img src="svnit_logo.png" alt="Logo 1" class="logo"></a>
        </div>
        <div class="title-container">
            <h1>OMNI WEB DRIVE</h1>
        </div>
        <div class="logo-container">
            <a href="https://drishti-svnit.github.io/drishti/"><img src="drishti_logo_white.png" alt="Logo 2" class="logo"></a>
        </div>
    </div>

    <div class="navbar">
        <a href="developers.html">Developers</a>
    </div>

    <div class="content-container">
        <div id="display">
            (X,Y)
        </div>

        <div class="controller">
            <div class="left">
                <div class="circular-button top-left"></div>
                <div class="circular-button bottom-left"></div>
            </div>
            <div class="joystick-container" title="Control the Omnibot with this joystick to move in any direction">
                <div class="joystick">
                    <div class="handle" id="handle"></div>
                </div>
            </div>
            <div class="right">
                <div class="circular-button top-right"></div>
                <div class="circular-button bottom-right"></div>
            </div>
        </div>

    </div>


    <script>
        const joystick = document.querySelector('.joystick-container');
        const handle = document.querySelector('.handle');


        let isJoystickPressed = false;
        let normX = 0;
        let normY = 0;

        joystick.addEventListener('mousedown', (e) => {
            isJoystickPressed = true;
            updateJoystick(e);
        });
        joystick.addEventListener('touchstart', (e) => {
            e.preventDefault();
            isJoystickPressed = true;
            updateJoystick(e.touches[0]);
        })


        document.addEventListener('mousemove', (e) => {
            if (isJoystickPressed) {
                updateJoystick(e);
            }
        });
        joystick.addEventListener('touchmove', (e) => {
            e.preventDefault();
            if (isJoystickPressed) {
                updateJoystick(e.touches[0]);
            }
        });

        document.addEventListener('mouseup', (e) => {
            isJoystickPressed = false;
            normX = 0;
            normY = 0;
            handle.style.transform = 'translate(-50%, -50%)';
            console.log("Normalized X:", normX);
            console.log("Normalized Y:", normY);
            document.getElementById('display').innerText = '(' + normX + ',' + normY + ')';
        });
        joystick.addEventListener('touchend', (e) => {
            e.preventDefault();
            isJoystickPressed = false;
            normX = 0;
            normY = 0;
            handle.style.transform = 'translate(-50%, -50%)';
            console.log("Normalized X:", normX);
            console.log("Normalized Y:", normY);
            document.getElementById('display').innerText = '(' + normX + ',' + normY + ')';
        });

        function updateJoystick(e) {
            const bounds = joystick.getBoundingClientRect();
            const centerX = bounds.left + bounds.width / 2;
            const centerY = bounds.top + bounds.height / 2;

            const deltaX = e.clientX - centerX;
            const deltaY = e.clientY - centerY;

            const distance = Math.min(joystick.offsetWidth / 2, Math.sqrt(deltaX ** 2 + deltaY ** 2));
            const angle = Math.atan2(deltaY, deltaX);

            const maxX = Math.cos(angle) * distance;
            const maxY = Math.sin(angle) * distance;

            handle.style.transform = `translate(calc(-50% + ${maxX}px), calc(-50% + ${maxY}px))`;

            // Normalize values between -1 and 1
            normX = maxX / (joystick.offsetWidth / 2);
            normY = -maxY / (joystick.offsetHeight / 2);

            normX=normX*128;
            normY=normY*128;

            // Use normX and normY for your application
            console.log("Normalized X:", normX);
            console.log("Normalized Y:", normY);
            document.getElementById('display').innerText = '(' + normX.toFixed(2) + ',' + normY.toFixed(2) + ')';
            document.getElementById('display').innerText = '(' + normX.toFixed(2) + ',' + normY.toFixed(2) + ')';
        }


    </script>
</body>

</html>

)=====";

// ipaddress/led1/on
//ipaddress/led1/off

// ipaddress/led2/on
//ipaddress/led2/off
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80); // server port 80
WebSocketsServer websockets(81);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Page Not found");
}


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) 
  {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

        // send message to client
        websockets.sendTXT(num, "Connected from server");
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] get Text: %s\n", num, payload);
      String message = String((char*)( payload));
      Serial.println(message);

      if(message == "LED 1 is OFF"){
        digitalWrite(LED1,LOW);
      }

      if(message == "LED 1 is ON"){
        digitalWrite(LED1,HIGH);
      }
      


  }
}

void setup(void)
{
  
  Serial.begin(115200);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  
  WiFi.softAP("techiesms", "");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }



  server.on("/", [](AsyncWebServerRequest * request)
  { 
   
  request->send_P(200, "text/html", controlpage);
  });

   server.on("/developers.html", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED1,HIGH);
  request->send_P(200, "text/html", devpage);
  });

  server.onNotFound(notFound);

  server.begin();  // it will start webserver
  websockets.begin();
  websockets.onEvent(webSocketEvent);

}


void loop(void)
{
 websockets.loop();
}
