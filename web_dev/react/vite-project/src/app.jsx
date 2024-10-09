
import { router } from "./routes";
import { Layout } from "./layout";

import { createBrowserRouter, RouterProvider } from "react-router-dom";

export function App() {
    // return <Header title = "MyTitle" ></Header>;

    
    // return (
    //     <> 
    //     <Layout>
    //         <main>
    //             <RouterProvider router={router}> </RouterProvider>
    //         </main>
    //     </Layout>
    //     </>
    // )
    
    return (
        <>
            <RouterProvider router={router}> </RouterProvider>
        </>
    )

    // return (
    //     <>
    //     <header>
    //         <Header></Header>
    //     </header>

    //     <main>
    //         <RouterProvider router={router}> </RouterProvider>
    //     </main>

    //     <footer></footer>
    //     </>
    // )
}


