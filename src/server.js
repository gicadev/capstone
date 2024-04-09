const socket = io("ws://echo.websocket.org");

const { Server } = require("socket.io");
const eiows = require("eiows");

const io = new Server(3000, {
  wsEngine: eiows.Server
});

socket.emit("hello", "world", (response)=> {
    console.log(response);
});

socket.on("hello", (arg, callback)=>{
    console.log(arg);
    callback("got it");
})
