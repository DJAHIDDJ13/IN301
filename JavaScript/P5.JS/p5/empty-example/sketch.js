function setup(){
  createCanvas(400, 400, WEBGL);

}

function draw(){
  background(200);
  rotateX(frameCount * 0.01);
  rotateY(frameCount * 0.01);
  box(200, 200, 200);
}