import { useEffect, useState } from "react";
import "./style.css"
import "bootstrap/dist/css/bootstrap.min.css"
//  hook ?

import { Link } from "react-router-dom";
export function ProductListA() {

    var [ProductList, setProductList] = useState([]);

    //  useCallback
    // useMemo

    // Variation 1 : Do this whenever component re-render
    // useEffect(() => {
    //     console.log("Component is re-render");
    // });

    // Variation 2 : Do this initial render
    // useEffect(() => {
    //     console.log("Component is re-render");
    // }, []);

    // Variation 3 : Do this based on dependency update
    // useEffect(() => {
    //     console.log("Component is re-render");
    // }, [ProductList]); 

    
    // useEffect(() => {
    //     console.log("Component is re-render");
    // }, [ProductList])

    // setTimeout(()=>{
    //     ProductList = [
    //         {name : "Product1", price: "Product1 Price"},
    //         {name : "Product2", price: "Product2 Price"}, 
    //         {name : "Product3", price: "Product3 Price"}
    //     ];
    // },1000)

   setTimeout(()=>{
        setProductList(
        ProductList = [
            {name : "Product1", price: "Product1 Price"},
            {name : "Product2", price: "Product2 Price"}, 
            {name : "Product3", price: "Product3 Price"}
        ])
    },1000)
    
 
    return <div>
        <table>
            <thead>
                <tr>
                <th style={{border: '2px solid black', padding :'5px'}}>Product Name</th>
                <th style={{border: '2px solid black', padding :'5px'}}>Product Price</th>
                </tr> 
            </thead>
            <tbody>
                {
                    ProductList.map((item, index) =>{
                        return (
                            <tr>
                                <td style={{border: '2px solid black', padding :'5px'}}>{item.name}</td>
                                <td style={{border: '2px solid black', padding :'5px'}}>{item.price}</td>
                            </tr>
                        );
                    })
                }
            </tbody>
        </table>
        <Link to={'/signup'}>
                Signup
        </Link>
        <Link to={'/signin'}>
                SignIn
        </Link>
    </div>;
} 