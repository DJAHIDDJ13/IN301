function setup(){
  createCanvas(400, 400);

}

function draw(){
  background(200);
  branch(50);
}

function branch(len){
  if(len < 2)
    return;
  stroke(0);
  line(0,0,0,-len);
  console.log(len);

  translate(0,-len);
  rotate(PI / 4);
  branch(len*0.67);

}
