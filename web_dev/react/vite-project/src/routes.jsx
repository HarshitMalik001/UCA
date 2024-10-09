import { ProductListA } from "./component/home/productList";
import { SignUp } from "./component/signup/signup";
import { SignIn } from "./component/signin/signin";
import { createBrowserRouter, RouterProvider } from "react-router-dom";
import { Children } from "react";
import { Layout } from "./layout";

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
            }
        ]
    }
])