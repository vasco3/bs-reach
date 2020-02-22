module Index = {
  Css.(global("body, *", [margin(px(0)), fontFamily("sans-serif")]));
  let className = Css.([marginRight(`px(10))] |> style);
  [@react.component]
  let make = () => {
    <div
      className=Css.(
        [
          margin(`auto),
          marginTop(`px(40)),
          maxWidth(`px(500)),
          padding2(~h=`zero, ~v=`px(10)),
        ]
        |> style
      )>
      <h1> "bs-reach"->React.string </h1>
      <p className=Css.([marginBottom(`px(20))] |> style)>
        "Simple examples of how to use bs-reach. For more documentation on Reach UI, visit the "
        ->React.string
        <a href="https://reacttraining.com/reach-ui">
          "official site"->React.string
        </a>
        "."->React.string
      </p>
      {["menu-button", "tabs", "tooltip", "dialog"]
       |> List.map(url => {
            <div key=url className>
              <a href={"/" ++ url}> url->React.string </a>
            </div>
          })
       |> Array.of_list
       |> React.array}
    </div>;
  };
};

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();
  <FocusVisible.Context>
    {switch (url.path) {
     | ["menu-button"] => <MenuButtonDemo />
     | ["tooltip"] => <TooltipDemo />
     | ["tabs"] => <TabsDemo />
     | ["dialog"] => <DialogDemo />
     | _ => <Index />
     }}
  </FocusVisible.Context>;
};