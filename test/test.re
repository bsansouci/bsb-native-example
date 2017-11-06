let run = () => Alcotest.(check(string))("same strings", "Hello", Index.run(Index.myData));

let test_set = [("MyTest", `Quick, run)];

/* Run it */
let () = Alcotest.run("My first test", [("test_set", test_set)]);
