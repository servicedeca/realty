<div id="owl-demo" class="owl-carousel owl-theme" style="opacity: 1; display: block;">
  <div class="owl-wrapper-outer">
    <div class="owl-wrapper" style="width: 2880px; left: 0px; display: block;">
      <?php foreach($complex as $value):?>
        <div class="owl-item" style="width: 240px;">
          <div class="item">
            <?php print $value['name']?>
            <?php print render($value['developer'])?>
            <?php print render($value['photo'])?>
            <?php print render($value['area'])?>
          </div>
        </div>
      <?php endforeach;?>
    </div>
  </div>
</div>