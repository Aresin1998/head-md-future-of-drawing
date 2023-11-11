const c = document.getElementById("myCanvas");
const W = c.width;
const H = c.height;
const ctx = c.getContext("2d");

function cmykToRGB(c,m,y,k) 
{
    function padZero(str) 
    {
        return "000000".substr(str.length)+str
    }

    var cyan = (c * 255 * (1-k)) << 16;
    var magenta = (m * 255 * (1-k)) << 8;
    var yellow = (y * 255 * (1-k)) >> 0;

    var black = 255 * (1-k);
    var white = black | black << 8 | black << 16;
    var color = white - (cyan | magenta | yellow );
    
    return ("#"+padZero(color.toString(16)));
}

function update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2)
{
    color_1 = cmykToRGB(c_1/100,m_1/100,y_1/100,k_1/100);
    color_2 = cmykToRGB(c_2/100,m_2/100,y_2/100,k_2/90);

    color_avg = cmykToRGB((c_2*K+c_1*(1-K))/100,
                        (m_2*K+m_1*(1-K))/100,
                        (y_2*K+y_1*(1-K))/100,
                        (k_2*K+k_1*(1-K))/100);

    ctx.fillStyle = color_1;
    ctx.fillRect(0, 0, W, H/2); 
    
    ctx.beginPath();
    ctx.arc(W/2, H/4, r, 0, 2*Math.PI);
    ctx.fillStyle = color_avg;
    ctx.fill(); 
    
    ctx.fillStyle = color_2;
    ctx.fillRect(0, H/2, W, H); 
    
    ctx.beginPath();
    ctx.arc(W/2, H/2+H/4, r, 0, 2*Math.PI);
    ctx.fillStyle = color_avg;
    ctx.fill(); 

}


c_1 = Math.random()*100; m_1 = Math.random()*100; y_1 = Math.random()*100; k_1 = Math.random()*100;
c_2 = Math.random()*100; m_2= Math.random()*100; y_2 = Math.random()*100; k_2 = Math.random()*100; 


r = (H/3)/4;
K = 0.5;

update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);


is_down = false;
drag = false;

c.addEventListener('mouseup', function (e) {
    is_down = false;
 });
c.addEventListener('mousedown', function (e) {
    is_down = true;
    let rect = c.getBoundingClientRect(); 
    
    let x = e.clientX - rect.left; 
    let y = e.clientY - rect.top; 

    if (y > H/2 - 50 && y > H/2 - 50)
    {
        drag = true;
    }
    else
    {
        drag = false;
    }
});
c.addEventListener('mousemove', function (e) {
    
    if (is_down)
    {
        if (drag)
        {
            is_down = true;
            let rect = c.getBoundingClientRect(); 
            
            let x = e.clientX - rect.left; 
            let y = e.clientY - rect.top; 

            ctx.clearRect(0, 0, W, H);
            
            K = y/H;    

            update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2)

        }
    }
 }); 

document.getElementById("c_1").addEventListener('input', function (e) {
    c_1 = document.getElementById("c_1").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});

 document.getElementById("m_1").addEventListener('input', function (e) {
    m_1 = document.getElementById("m_1").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});

document.getElementById("y_1").addEventListener('input', function (e) {
    y_1 = document.getElementById("y_1").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});

document.getElementById("k_1").addEventListener('input', function (e) {
    k_1 = document.getElementById("k_1").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});


document.getElementById("c_2").addEventListener('input', function (e) {
    c_2 = document.getElementById("c_2").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});

 document.getElementById("m_2").addEventListener('input', function (e) {
    m_2 = document.getElementById("m_2").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});

document.getElementById("y_2").addEventListener('input', function (e) {
    y_2 = document.getElementById("y_2").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});

document.getElementById("k_2").addEventListener('input', function (e) {
    c_2 = document.getElementById("k_2").value;
    update_color(K, c_1,m_1,y_1,k_1, c_2,m_2,y_2,k_2);
});
