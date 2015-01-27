
<div class="container-fluid container-fix">
  <div class="row">
    <div class="col-xs-6 fifty height header-block fix">
      <div class="title-line header-text padd-bot">
        <h2>
          <?php print $image_map?>
          <?php print t('Map of buildings')?>
        </h2>
      </div>
      <div class="head-line marg-top">
      </div>
    </div>
    <div class="col-xs-6 fifty height zero-padding header-block">
      <div class="header-text padd-bot">
        <h1>
          <?php print t('Any suggestions on a map of your city')?>
        </h1>
        <h2>
          <?php print t('Find what suits you')?>
        </h2>
      </div>
    </div>
  </div>
  <div class="col-xs-12 header-parent">
    <div class="form-group c-select">
      <?php print render($search_map_form['category'])?>
    </div>
    <div id="filters">
      <ul>
        <li>
          <a data-toggle="modal" data-target=".modal-map-area">Район</a>
        </li>
        <li class="store">
          <input type="checkbox" id="mapcheck">
          <label class="map-hint"  for="mapcheck">Акции</label>
        </li>
      </ul>
    </div>
  </div>
</div>
  <div class="row relative">
    <div class="col-xs-9 fiftyplus double-big-height poster-photo parent">
      <?php print render($map);?>
    </div>
    <div class="col-xs-3 double-big-height fifty-minus zero-padding parent">
      <div class="col-xs-12 height zero-padding">
        <img src="images/image-c2.png" class="title-image">
      </div>
      <div class="col-xs-12 beige-block big-height zero-padding">
        <div class="col-xs-12 quarter-item zero-padding">
          <img src="images/logo-z2.png" class="logo-z vertical-logo">
        </div>
        <div class="col-xs-12 second quarter-item zero-padding display-table">
          <div class="vertical">
            <h2>Жилой комплекс Марсель</h2>
          </div>
          <div class="gorizont-line">
          </div>
        </div>
        <div class="col-xs-12 third quarter-item zero-padding item-text-field">
          <p>"Марсель" - дом на набережной</p>
        </div>
        <div class="col-xs-12 fourth button-item zero-padding item-text-field">
          <a href="#" class="button-info button-info-top">Подробности</a>
        </div>
      </div>
    </div>
  </div>


<div class="modal fade modal-map-area" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p><?php print t('Select area')?></p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print render($img_close)?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">

      <?php foreach($areas as $key => $area):?>
        <div class="col-xs-4">
          <li>
            <label class="checkbox-inline check-style">
              <input type="checkbox" class="inlineCheckbox1 CheckboxMapArea" value="<?php print $key?>"><?php print $area; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>

    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <a href="#" class="search-button modal-but"><?php print t('select')?></a>
      </button>
    </div>
  </div>
</div>

<div id="form-search-hidden">
  <?php print render($search_map_form)?>
</div>