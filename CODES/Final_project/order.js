

if (document.readyState == 'loading') {
    document.addEventListener('DOMContentLoaded', ready)
} else {
    ready()
}

arr = []

function ready() {
    var removeCartItemButtons = document.getElementsByClassName('btn-danger')
    for (var i = 0; i < removeCartItemButtons.length; i++) {

        var button = removeCartItemButtons[i]
        button.addEventListener('click', removeCartItem)
    }
    var quantityInputs = document.getElementsByClassName('order-quantity-input')
    for (var i = 0; i < quantityInputs.length; i++) {

        var input = quantityInputs[i]
        input.addEventListener('click', quantityChanged)
    }
    var buyFoodButtons = document.getElementsByClassName('buy-food-image')
    for (var i = 0; i < buyFoodButtons.length; i++) {

        var button = buyFoodButtons[i]
        button.addEventListener('click', addFood)
    }

    document.getElementsByClassName('btn-purchase')[0].addEventListener('click', purchaseClicked)

    document.getElementsByClassName('output-button')[0].addEventListener('click', repeatOrder)

}




function repeatOrder(event){
    if (arr.length == 0) {
        alert("No order yet")
    }
    else{
    

    var cartRow = document.createElement('div')
    cartRow.classList.add('order-foods')
    var cartItems = document.getElementsByClassName('order-foods')[0]
    var cartRowContents = arr[0]
    cartRow.innerHTML = cartRowContents
    cartItems.append(cartRow) 
    const removeButtons = cartRow.querySelectorAll('.btn-danger');
    const quantityInputs = cartRow.querySelectorAll('.order-quantity-input');

    
    removeButtons.forEach(button => button.addEventListener('click', removeCartItem));
    quantityInputs.forEach(input => input.addEventListener('change', quantityChanged));
    updateCartTotal()
// //     var items = saveOrder();
// // for (var i = 0; i < items.length; i++) {
// //     var item = items[i];
// //     addFoodtoCart(item.title, item.price, item.imageSrc);
// }

    }
}




function purchaseClicked(event) {
    var amount = document.getElementById('totalPrice').innerText
    var pay = document.getElementById('payamount').value
    var name = document.getElementsByClassName('customer-name')[0]
    var price = parseFloat(amount.replace('₱', ''))
    pay = Number(pay)

    console.log(pay)
    console.log(price)
    console.log(pay - price)
   

    if (pay - price >= 0 && name.value != "") {
        alert("Thank you")
        saveOrder()
        printReceipt(pay, price)
        var cartItems = document.getElementsByClassName('order-foods')[0]
        while (cartItems.hasChildNodes()) {
            cartItems.removeChild(cartItems.firstChild)
        }
        updateCartTotal()



    }
    else if(name.value == ""){
        alert('Please Input Name')
    }
    else {
        alert('Insufficient Funds!')
    }


}

function printReceipt(pay, price) {
    
    const div = document.querySelector('.order-foods')
    const totaldiv = document.querySelector('.order-total')
    const name = document.querySelector('.customer-name')
    const input = document.querySelector('.order-quantity-input')
    const customerName = name.value
    
   



    const buttons = div.querySelectorAll('button');
    buttons.forEach(button => button.remove());

    const images = div.querySelectorAll('img');
    images.forEach(image => image.remove());

    const inputs = div.querySelectorAll('input');
    inputs.forEach(function (put) {
        var val = put.value
        var textNode = document.createTextNode(`x ${val}`)
        var inputElementParent = put.parentNode;
        inputElementParent.replaceChild(textNode, put)
    })




    const newWindow = window.open()

    newWindow.document.write('<!DOCTYPE html>');
    newWindow.document.write('<html>');
    newWindow.document.write('<head>');
    newWindow.document.write('<title>Receipt</title>');
    newWindow.document.write('<link rel="stylesheet" href="order.css" />')
    newWindow.document.write('</head>');
    newWindow.document.write('<body>');
    newWindow.document.write('<h1>RECEIPT</h1>')
    newWindow.document.write(`<h1>Name:${customerName}</h1>`);
    newWindow.document.write("<h2>Ordered Items</h2>");
    newWindow.document.write(div.innerHTML);
    newWindow.document.write(totaldiv.innerHTML);
    newWindow.document.write(`<h2>Amount paid: ₱${pay} Change: ₱${Math.round((pay - price) * 100) / 100}</h2>`)
    newWindow.document.write('</body>');
    newWindow.document.write('</html>');
   


}


function addFood(event) {
    var button = event.target
    var shopFood = button.parentElement.parentElement
    var title = shopFood.getElementsByClassName('buy-food-title')[0].innerText
    var price = shopFood.getElementsByClassName('buy-food-price')[0].innerText
    var imageSrc = shopFood.getElementsByClassName('buy-food-image')[0].src
    addFoodtoCart(title, price, imageSrc)
    updateCartTotal()

}

function addFoodtoCart(title, price, imageSrc) {
    var cartRow = document.createElement('div')
    cartRow.classList.add('order-row')
    var cartItems = document.getElementsByClassName('order-foods')[0]
    var cartItemsNames = cartItems.getElementsByClassName('order-food-title')
    for (var i = 0; i < cartItemsNames.length; i++) {
        if (cartItemsNames[i].innerText == title) {
            alert("Already added to cart")
            return
        }

    }

    var cartRowContents = `
       
        <div class="order-food order-column">
        <img class="order-food-image" src="${imageSrc}" width="100" height="100">
        <span class="order-food-title">${title}</span>
    </div>
    <span class="order-price order-column">${price}</span>
    <div class="order quantity order-column">
        <input class="order-quantity-input" type="number" value="1">
        <button class="btn btn-danger" type="button">REMOVE</button>
    </div>
    <div class="order-subtotal order-column">                
    <span class="order-subtotal-price">20</span>
    
    </div>`
    cartRow.innerHTML = cartRowContents
    cartItems.append(cartRow)
    cartRow.getElementsByClassName('btn-danger')[0].addEventListener('click', removeCartItem)
    cartRow.getElementsByClassName('order-quantity-input')[0].addEventListener('change', quantityChanged)

}


function removeCartItem(event) {
    console.log("clicked")
    var buttonClicked = event.target
    buttonClicked.parentElement.parentElement.remove()
    updateCartTotal()

}

function quantityChanged(event) {
    var input = event.target
    if (isNaN(input.value) || input.value <= 0) {
        input.value = 1
    }
    updateCartTotal()
}


function updateCartTotal() {
    var cartItemContainer = document.getElementsByClassName('order-foods')[0]
    var cartRows = cartItemContainer.getElementsByClassName('order-row')
    var total = 0
    for (var i = 0; i < cartRows.length; i++) {
        var cartRow = cartRows[i]
        var priceElememt = cartRow.getElementsByClassName('order-price')[0]
        var quantityElement = cartRow.getElementsByClassName('order-quantity-input')[0]
        var price = parseFloat(priceElememt.innerText.replace('₱', ''))
        var quantity = quantityElement.value
        total += (price * quantity)
        document.getElementsByClassName('order-subtotal-price')[i].innerText = Math.round((price * quantity) * 100) / 100
    }
    total = Math.round(total * 100) / 100
    document.getElementsByClassName('order-total-price')[0].innerText = '₱' + total
}





function saveOrder() {
    const div = document.querySelector('.order-foods')
    const inputs = div.querySelectorAll('input');
    inputs.forEach(function (input) {
        var val = input.value
        input.value = val;
    })
    arr.push(div.innerHTML)
}

// function saveOrder() {
//     var orderRows = document.getElementsByClassName('order-row');
//     var items = [];
//     for (var i = 0; i < orderRows.length; i++) {
//         var orderRow = orderRows[i];
//         var title = orderRow.getElementsByClassName('order-food-title')[0].innerText;
//         var price = orderRow.getElementsByClassName('order-price order-column')[0].innerText;
//         var quantity = orderRow.getElementsByClassName('order-quantity-input')[0].value;
//         items.push({title: title, price: price, quantity: quantity});
//     }
//     return items;
// }

