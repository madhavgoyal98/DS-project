<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Navigation System</title>
<script src = "homepage.js" language="javascript" type="text/javascript"></script>
</head>

<body bgcolor=rgba(241,211,212,1.00)>
<h1 align="center">Navigation System</h1>
<div id="div1" style="height: 250px; width: 300px; position: relative; left: 50px; top: 50px; float: left; border: solid; padding: 5px">
    <form name="form1" action="homepage.php" method="post">
        <p>
            1. Select your location  <select name="source" id="source">
                                        <option value="AjantaHospital">Ajanta Hospital</option>
                                        <option value="Mocha">Mocha</option>
                                        <option value="EasyDay">Easy Day</option>
                                        <option value="Pantaloons">Pantaloons</option>
                                        <option value="CafeCoffeeDay">Cafe Coffee Day</option>
                                        <option value="Dominos">Dominos</option>
                                        <option value="LifePlusHospital">Life Plus Hospital</option>
                                        <option value="MaxGrocery">Max Grocery</option>
                                        <option value="AnandHospital">Anand Hospital</option>
                                        <option value="PizzaHut">Pizza Hut</option>
                                     </select>
        </p>
        <p>
            2. Search by  <label><input type="radio" name="option" value=1 id="option" onClick="displayDest()">Destination</label>  <label><input type="radio" id="option" name="option" value=2 onClick="displayCat()">Category</label>
      </p>
        <div id="dest_cat">
        </div>
        <br>
        <div id="buttons">
        </div>
  </form>
    <?php
        if(isset($_POST['submit']))
        {
            $src = $_POST['source'];
            $option = $_POST['option'];
            
            if($option == "1")
            {
                $destination = $_POST['dest'];
                $command = "f: && cd F:\college\sem_4\DS project && "."final ".$src." 1 ".$destination;
                
                $result = explode(" ", shell_exec($command));
                
                echo("Minimum Distance: $result[0]\n");
                echo "<ol type=1>";
                
                for($i = 1; $i<count($result); $i++)
                {
                    echo "<li>".$result[$i];
                }
                
                echo "</ol>";
            }
            elseif($option == "2")
            {
                $category = $_POST['cat'];
                $command = "f: && cd F:\college\sem_4\DS project && "."final ".$src." 2 ".$category;
                
                $result = explode(" ", shell_exec($command));
                
                echo "Nearest Loacation: ".$result[0];
                echo "<br>";
                echo "Minimum Distance: ".$result[1]."\n";
                echo "<ol type=1>";
                
                for($i = 2; $i<count($result); $i++)
                {
                    echo "<li>".$result[$i];
                }
                
                echo "</ol>";
            }
        }
    ?>
</div>

<div style="height: 350px; width: 700px; position: relative; left: 400px; top: 50px; right: 200px; float: left;">
    <img src="city.png" height="350px" width="700px">
</div>
</body>
</html>