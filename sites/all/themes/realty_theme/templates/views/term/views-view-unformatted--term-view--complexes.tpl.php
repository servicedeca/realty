<div class="container">
  <h1 calss="title-complex-sl" >
    <?php print t('New in town')?>
  </h1>
  <div class="row">
    <div id="owl-demo" class="owl-carousel owl-theme">
      <?php foreach($complex as $value):?>
        <div class="item">
          <div class="complex-name-sl">
            <?php print render($value['name'])?>
          </div>
          <div class="complex-photo-sl">
            <?php print render($value['photo'])?>
          </div>
          <div class="complex-area-sl">
            <?php print t('Area:'); ?>
            <?php print render($value['area'])?>
          </div>
          <div class="complex-deadline-sl">
            <?php print t('Deadline:'); ?>
            <?php print $value['deadline']?>
          </div>
          <div class="complex-developer-sl">
            <?php print t('Developer:'); ?>
            <?php print render($value['developer'])?>
          </div>
        </div>
      <?php endforeach;?>
    </div>
    <div class="customNavigation">
      <a class="btn prev">Previous</a>
      <a class="btn next">Next</a>
    </div>
  </div>
</div>
