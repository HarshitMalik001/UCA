import { ProductListA } from "./component/home/productList";
import { SignUp } from "./component/signup/signup";
import { SignIn } from "./component/signin/signin";
import { createBrowserRouter, RouterProvider } from "react-router-dom";
import { Children } from "react";
import { Layout } from "./layout";
import { CreateProduct } from "./component/CreateProduct";

export const router = createBrowserRouter([
    {
        path: "/",
        element: <Layout></Layout>,
        children: [
            {
                path: "/",
                element: <ProductListA></ProductListA>
            },
            {
                path: "/signup",
                element: <SignUp></SignUp>
            },
            {
                path: "/signin",
                element: <SignIn></SignIn>
            },
            {
                path: "createproduct",
                element: <CreateProduct fromUpdate = "0"></CreateProduct>
            }
        ]
    }
])