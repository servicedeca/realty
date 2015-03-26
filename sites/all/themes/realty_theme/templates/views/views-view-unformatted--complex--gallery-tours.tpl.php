<div class="container fin">
  <?php if(isset($image_pano)):?>
  <a href="#" class="col-xs-10 col-xs-offset-1 zero-padding dt-item" data-toggle="modal" data-target=".modal_dt">
    <?php print $image_pano;?>
    <div class="dticon animated">360<sup class="o">o</sup>
    </div>
  </a>
  <?php endif?>
</div>

<div class="modal fade modal_dt" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-dt zero-padding">
    <div class="col-xs-12 header-container-modal header-block margin-bottom-50">
      <div class="modal-text">
        <p>3d тур</p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>
    </div>
    <?php print $pano;?>
  </div>
</div>

