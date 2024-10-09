import { useRef } from "react"

export function SignIn() {


    const emailRef = useRef(null);
    const passwordRef = useRef(null);

    const submitHandler = (event) =>{
        event.preventDefault();

        var formValueObject = {
            email : emailRef.current.value,
            password : passwordRef.current.value
        }

        console.log(formValueObject);

        if(formValueObject.firstName && formValueObject.lastName && formValueObject.email && formValueObject.password)
        {
            console.log("Form Submitted");
        }
        else{
            alert("some error");
        }
    }
    return <>
        <form>
            <div class="mb-3">
                <label for="exampleInputEmail1" class="form-label">Email address</label>
                <input type="email" class="form-control" id="exampleInputEmail1" ref={emailRef}  aria-describedby="emailHelp" />
            </div>
            <div class="mb-3">
                <label for="exampleInputPassword1" class="form-label">Password</label>
                <input type="password" class="form-control" ref={passwordRef}  id="exampleInputPassword1" />
            </div>
            <div class="mb-3 form-check">
                <input type="checkbox" class="form-check-input" id="exampleCheck1" />
                <label class="form-check-label" for="exampleCheck1">Check me out</label>
            </div>
            <button type="submit" class="btn btn-primary" onClick={submitHandler}>Submit</button>
        </form>
    </>
}



// Synthetic Events in REact
//  What is a wrapper
