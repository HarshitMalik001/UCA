// import { ProductListA } from "./component/home/productList";
import { Header } from "./header";
import { Outlet } from "react-router-dom";
// Layout({children, prop1, prop2}) 

export function Layout({children})
{
    // console.log(children);
    return (
        <>
        <header>
            <Header></Header>
        </header>
        {/* {children} */}
        <Outlet/>
        <footer></footer>
        </>
    )
}