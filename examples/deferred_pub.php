
<?php 
// example for deferred publish  延迟发布例子

//the nsqd tcp addr that you want to publish
$nsqdAddr = array(
    "127.0.0.1:4150",
    "127.0.0.1:4154",
);

$deferred = new Nsq();
$isTrue = $deferred->connectNsqd($nsqdAddr);

for($i = 0; $i < 9; $i++){

    $delayMsec = 3600000;
    //deferredPublish(string topic,string message, int millisecond); 
    $deferred->deferredPublish("test", "the message will be received after".$delayMsec/(1000*60)."minutes", $delayMsec);

}
$deferred->closeNsqdConnection();
