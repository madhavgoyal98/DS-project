function displayDest()
{
    var parent = document.getElementById('dest_cat');
    
    while(parent.firstChild)
    {
        parent.removeChild(parent.firstChild);
    }
    
    document.getElementById('buttons').innerHTML = '';
    
    parent.innerHTML = '3. Select destination  <select name="dest" id="dest" onClick="displaySubmit()"><option value="AjantaHospital">Ajanta Hospital</option><option value="Mocha">Mocha</option><option value="EasyDay">Easy Day</option><option value="Pantaloons">Pantaloons</option><option value="CafeCoffeeDay">Cafe Coffee Day</option><option value="Dominos">Dominos</option><option value="LifePlusHospital">Life Plus Hospital</option><option value="MaxGrocery">Max Grocery</option><option value="AnandHospital">Anand Hospital</option><option value="PizzaHut">Pizza Hut</option></select><br>';
}

function displayCat()
{
    var parent = document.getElementById('dest_cat');
    
    while(parent.firstChild)
    {
        parent.removeChild(parent.firstChild);
    }
    
    document.getElementById('buttons').innerHTML = '';
    
    parent.innerHTML = '3. Select category  <select name="cat" id="cat" onClick="displaySubmit()"><option value="Hospital">Hospital</option><option value="FoodPlace">Food Place</option><option value="Grocery">Grocery</option><option value="ClothShopping">Cloth Shopping</option></select><br>';
}

function displaySubmit()
{
    var parent = document.getElementById('buttons');
    
    parent.innerHTML = '<button name="submit" id="submit" onClick="document.getElementsByName("form1").submit();">Submit</button>   <input type="reset">';
}