const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>

  <style>
    #demo {
      text-align: center;
    }

  </style>
  <div id="demo">
    <h1>ESP8266 AJAX DEMO</h1>
    <button type="button" onclick="sendData(1)">WHITE LED ON</button>
    <button type="button" onclick="sendData(0)">WHITE LED OFF</button>
    <h1>LED State is : <span id="LEDState">N/A</h1></span>
    <h1>ADC Value is : <span id="ADCValue">0 </h1></span>
    <h1>Random Number Value is : <span id="RANDOM_NUM"></h1></span><br>
  </div>

  <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
  <div id="ADC_Gauge_Div" style="width:280px; height: 280px;margin: auto;
"></div>
  <div id="Rand_Num_Gague_Div" style="width:280px; height: 280px;margin: auto;"></div>

  <script>

    google.charts.load('current', { 'packages': ['gauge'] });
    google.charts.setOnLoadCallback(drawADCGauge);
    google.charts.setOnLoadCallback(drawRandNumGauge);

    var gaugeOptions = {
      min: 0, max: 1024, yellowFrom: 750, yellowTo: 950,
      redFrom: 950, redTo: 1024, minorTicks: 5
    };

    var gaugeOptions2 = {
      min: 0, max: 5, yellowFrom: 2, yellowTo: 4,
      redFrom: 4, redTo: 5, minorTicks: 5
    };

    var gauge, gauge2;

    function drawADCGauge() {
      //https://developers.google.com/chart/interactive/docs/reference#DataTable
      gaugeData = new google.visualization.DataTable();
      gaugeData.addColumn('number', 'ADC');
      //gaugeData.addColumn('number', 'RandomNum');
      //gaugeData.addRows(2);
      gaugeData.addRows(1);

      //Left Gauge
      gaugeData.setCell(0, 0, 0);
      //Right Gauge
      //gaugeData.setCell(0, 1, 0);

      gauge = new google.visualization.Gauge(document.getElementById('ADC_Gauge_Div'));
      //gauge2 = new google.visualization.Gauge(document.getElementById('ADC_Gauge_Div'));

      gauge.draw(gaugeData, gaugeOptions);
      //gauge2.draw(gaugeData, gaugeOptions2);

    }

    function drawRandNumGauge() {
      //https://developers.google.com/chart/interactive/docs/reference#DataTable
      gaugeData2 = new google.visualization.DataTable();
      gaugeData2.addColumn('number', 'RandomNum');
      gaugeData2.addRows(1);

      //Left Gauge
      gaugeData2.setCell(0, 0, 0);
      gauge2 = new google.visualization.Gauge(document.getElementById('Rand_Num_Gague_Div'));
      gauge2.draw(gaugeData2, gaugeOptions2);

    }

    function adc_Value(dir) {
      //Left Gauge
      gaugeData.setValue(0, 0, dir);
      gauge.draw(gaugeData, gaugeOptions);
    }

    function random_Num(num) {
      //Right Gauge
      gaugeData2.setValue(0, 0, num);
      gauge2.draw(gaugeData2, gaugeOptions2);
    }


    function sendData(led) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("LEDState").innerHTML = this.responseText;
        }
      };
      xhttp.open("GET", "setLED?LEDstate=" + led, true);
      xhttp.send();
    }

    setInterval(function () {
      // Call a function repetatively with 2 Second interval
      getData();
    }, 500); //2000mSeconds update rate

    function getData() {
      // -------------------------------------[ ADC ]------------------------------------- // 
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("ADCValue").innerHTML =
            this.responseText;

          // Sends data to 
          adc_Value(document.getElementById("ADCValue").innerHTML =
            this.responseText);
        }
      };
      xhttp.open("GET", "readADC", true);
      xhttp.send();

      // -------------------------------------[ Random Number ]------------------------------------- // 
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("RANDOM_NUM").innerHTML =
            this.responseText;

          random_Num(document.getElementById("RANDOM_NUM").innerHTML =
            this.responseText);
        }
      };
      xhttp.open("GET", "randomNum", true);
      xhttp.send();



    }
  </script>
</body>

</html>
)=====";