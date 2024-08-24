// // window.alert("bye again")

// function init(){
//     document.getElementById("jsworld").innerHTML="hello javascript";
// }

// init()


function renderData() {

    

    function getProductList() {
        productListFromServer=productList;
        initProductListTable()
    }


    function initProductListTable() {
        console.log("initializing products list");
        document.getElementById("productmenu").innerHTML = `
        <h2>List of Products</h2>
            <table>
                <thead>
                    <tr>
                        <th>Sr. No .</th>
                        <th>Product Name</th>
                        <th>Product Details</th>
                        <th>Product Price</th>
                    </tr>
                </thead>
                <tbody>
                    ${getProductListElementmap()}
                </tbody>
            </table>
            <div>${arr}</div>
        `
    }

    let arr = [1,2,3];

    function getProductListElement() {
        var rows = "";
        for (var i = 0; i < productListFromServer.length; i++) {
            rows = rows + `
                <tr>
                    <td>${i + 1}</td>
                    <td>${productListFromServer[i].name}</td>
                    <td>${productListFromServer[i].description}</td>
                    <td>${productListFromServer[i].price}</td>
                </tr>
            `
        }
        return rows;

    }

    function getProductListElementmap() {
        if (!productListFromServer||productListFromServer?.length == 0) {
            return "loading data";
        }
        var l = productListFromServer?.map((i, index) => {
            return `
                <tr>
                    <td>${index + 1}</td>
                    <td>${i.name}</td>
                    <td>${i.description}</td>
                    <td>${i.price}</td>
                </tr>
            `
        })
        return l.join("");
    }

    
    initProductListTable()
    setTimeout(getProductList, 5000);
    var productListFromServer = [];

}


renderData();