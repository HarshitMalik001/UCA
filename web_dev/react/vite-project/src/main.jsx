import { createRoot } from "react-dom/client";
import { App as NewApp} from "./app";

const reactProjectRoot = createRoot(document.getElementById("root"));

reactProjectRoot.render(<NewApp/>);