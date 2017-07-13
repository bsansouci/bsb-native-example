let () = {
  let request = [%lwt
    {
      let addresses = Lwt_unix.getaddrinfo "google.com" "80" [];
      let google = (List.hd addresses).Lwt_unix.ai_addr;
      Lwt_io.(
        with_connection
          google
          (
            fun (incoming, outgoing) => [%lwt
              {
                let () = write outgoing "GET / HTTP/1.1\r\n";
                [%lwt
                  {
                    let () = write outgoing "Connection: close\r\n\r\n";
                    [%lwt
                      {
                        let response = read incoming;
                        Lwt.return (Some response)
                      }
                    ]
                  }
                ]
              }
            ]
          )
      )
    }
  ];
  let timeout = [%lwt
    {
      let () = Lwt_unix.sleep 5.;
      Lwt.return None
    }
  ];
  switch (Lwt_main.run (Lwt.pick [request, timeout])) {
  | Some response => print_string response
  | None =>
    prerr_endline "Request timed out";
    exit 1
  }
};
