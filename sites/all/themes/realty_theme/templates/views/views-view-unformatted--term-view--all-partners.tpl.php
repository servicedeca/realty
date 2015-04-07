<div class="container fin margin-bottom">
  <div class="col-xs-12 allcomplex-filter">
  </div>
  <div class="col-xs-12 develop-complex zero-padding">
    <?php if (isset($partners)):?>
      <?php foreach ($partners as $partner):?>
        <?php print $partner;?>
      <?php endforeach;?>
    <?php endif;?>
  </div>
</div>