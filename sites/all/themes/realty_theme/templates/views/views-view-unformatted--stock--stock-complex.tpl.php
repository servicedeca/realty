<div class="container fin">
  <div id="owl-demo" class="col-xs-12 zero-padding owl-carousel owl-theme">
    <?php if(isset($stocks)):?>
      <?php foreach($stocks as $stock):?>
        <div class=" col-xs-12 item">
          <div class=" col-xs-12 stock-title">
            <p>
              <?php print $stock['title']?>
            </p>
          </div>
          <div class="col-xs-5 zero-padding">
            <?php if(isset($stock['image'])):?>
              <?php print $stock['image']?>
            <?php endif;?>
          </div>
          <div class="col-xs-7 stock-text-block zero-padding">
            <div class="vertical">
              <?php print $stock['description'];?>
            </div>
          </div>
        </div>
      <?php endforeach;?>
    <?php endif;?>
  </div>
</div>